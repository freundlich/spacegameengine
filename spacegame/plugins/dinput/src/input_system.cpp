#include <stdexcept>
#include "../../../core/main/ptr_cast.hpp"
#include "../../../core/main/win32_window.hpp"
#include "../input_system.hpp"
#include "../keyboard.hpp"
#include "../mouse.hpp"

sge::dinput::input_system::input_system(const win32_window_ptr wnd)
: wnd(wnd), keyboards(0), mice(0), joysticks(0)
{
	IDirectInput8* d;
	if(DirectInput8Create(GetModuleHandle(0),
	                      DIRECTINPUT_VERSION,
	                      IID_IDirectInput8,
	                      reinterpret_cast<LPVOID*>(&d),
	                      0) != DI_OK)
		throw std::runtime_error("Cannot create direct input");
	di.reset(d);

	if(di->EnumDevices(DI8DEVCLASS_ALL,
	                   di_enum_devices_callback,
	                   this,
	                   DIEDFL_ATTACHEDONLY) != DI_OK)
		throw std::runtime_error("DirectInput Enumeration failed");
}

sge::input_array& sge::dinput::input_system::get_input()
{
	for(device_array::iterator it = devices.begin(); it != devices.end(); ++it)
		(*it)->get_input(input);
	return input;
}

char sge::dinput::input_system::keycode_to_char(const key_code key, const modifier_state& mod_state) const
{
	static const HKL layout = GetKeyboardLayout(0);
	static boost::array<BYTE,256> state;
	const BYTE key_up = 0, key_down = 0x80;
	state[VK_SHIFT] = mod_state.shift_down ? key_down : key_up;
	state[VK_MENU] = mod_state.alt_down ? key_down : key_up;
	state[VK_CONTROL] = mod_state.ctrl_down ? key_down : key_up;

	const unsigned dik = key_conv.create_dik(key);
	const unsigned vk = MapVirtualKeyEx(dik,1,layout);

	WORD result;
	if(ToAsciiEx(vk,dik,state.c_array(),&result,0,layout) == 1)
		return *reinterpret_cast<char*>(&result);
	return 0; // not supported
}

BOOL sge::dinput::input_system::di_enum_devices_callback(LPCDIDEVICEINSTANCE ddi, LPVOID s)
{
	input_system& sys = *static_cast<input_system*>(s);
	const unsigned char dev_type = static_cast<unsigned char>(ddi->dwDevType & 0xFF);

	switch(dev_type) {
	case DI8DEVTYPE_KEYBOARD:
		sys.devices.push_back(new keyboard(sys.di,ddi.tszProductName,ddi.guidInstance,sys.keyboards,sys.wnd->hwnd(),&sys.key_conv));
		++sys.keyboards;
		break;
	case DI8DEVTYPE_MOUSE:
		sys.devices.push_back(new mouse(sys.di,ddi.tszProductName,ddi.guidInstance,sys.mice,sys.hwnd));
		++sys.mice;
		break;
	/*
	case DI8DEVTYPE_JOYSTICK:
		SetDataFormat(Device,&c_dfDIJoystick2);

		DIPROPRANGE	Range;
		Range.diph.dwHeaderSize	= sizeof(DIPROPHEADER);
		Range.diph.dwSize		= sizeof(DIPROPRANGE);
		Range.diph.dwObj		= 0;
		Range.diph.dwHow		= DIPH_DEVICE;
		Range.lMin				= -1000;
		Range.lMax				= +1000;
		SetProperty(Device,DIPROP_RANGE,&Range.diph);

		DIPROPDWORD	DeadZone;
		DeadZone.diph.dwHeaderSize	= sizeof(DIPROPHEADER);
		DeadZone.diph.dwSize		= sizeof(DIPROPDWORD);
		DeadZone.diph.dwObj			= 0;
		DeadZone.diph.dwHow			= DIPH_DEVICE;
		DeadZone.dwData				= 1000;
		SetProperty(Device,DIPROP_DEADZONE,&DeadZone.diph);

		DIPROPDWORD	Saturation;
		Saturation.diph.dwHeaderSize	= sizeof(DIPROPHEADER);
		Saturation.diph.dwSize			= sizeof(DIPROPDWORD);
		Saturation.diph.dwObj			= 0;
		Saturation.diph.dwHow			= DIPH_DEVICE;
		Saturation.dwData				= 9000;
		SetProperty(Device,DIPROP_SATURATION,&Saturation.diph);

		++sys->joysticks;*/
	}
	return DIENUM_CONTINUE;
}
