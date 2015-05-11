/*
Example of two different ways to process received OSC messages using oscpack.
Receives the messages from the SimpleSend.cpp example.
*/

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <windows.h>

#if defined(__BORLANDC__) // workaround for BCB4 release build intrinsics bug
namespace std {
	using ::__strcmp__;  // avoid error: E2316 '__strcmp__' is not a member of 'std'.
}
#endif

#include "osc/OscReceivedElements.h"
#include "osc/OscPacketListener.h"
#include "ip/UdpSocket.h"


#define PORT 7400
using namespace osc;

class ExamplePacketListener : public osc::OscPacketListener {
protected:

	virtual void ProcessMessage(const osc::ReceivedMessage& m,
		const IpEndpointName& remoteEndpoint)
	{
		(void)remoteEndpoint; // suppress unused parameter warning


		static bool signalPush = false;
		static bool signalLastPush = false;
		static bool state = false;

		try{
			// argument stream, and argument iterator, used in different
			// examples below.
			ReceivedMessageArgumentStream args = m.ArgumentStream();
			ReceivedMessage::const_iterator arg = m.ArgumentsBegin();

			if (std::strcmp(m.AddressPattern(), "/COG/NEUTRAL") == 0){

				// example #1:
				// parse an expected format using the argument stream interface:
				//bool a1;
				//osc::int32 a2;
				float a3;
				//const char *a4;
				//args >> a1 >> a2 >> a3 >> a4 >> osc::EndMessage;
				args >> a3 >> osc::EndMessage;

				std::cout << "Neutral Argument count = " << m.ArgumentCount() << " - Value = " << a3 << "." << std::endl;
				//std::cout << "received '/AFF/Excitement' message with arguments: "
				//        << a1 << " " << a2 << " " << a3 << " " << a4 << "\n";
				signalPush = false;

			}
			else if (std::strcmp(m.AddressPattern(), "/COG/PUSH") == 0){
				// This structure will be used to create the keyboard
				// input event.
				signalPush = true;

				// example #2:
				// parse an expected format using the argument iterator interface
				// this is a more complicated example of doing the same thing
				// as above.
				/*bool a1 = (arg++)->AsBool();
				int a2 = (arg++)->AsInt32();
				float a3 = (arg++)->AsFloat();
				const char *a4 = (arg++)->AsString();
				if( arg != m.ArgumentsEnd() )
				throw ExcessArgumentException();

				std::cout << "received '/test2' message with arguments: "
				<< a1 << " " << a2 << " " << a3 << " " << a4 << "\n";
				*/

				float a3;
				//const char *a4;
				//args >> a1 >> a2 >> a3 >> a4 >> osc::EndMessage;
				args >> a3 >> osc::EndMessage;

				std::cout << "Push Argument count = " << m.ArgumentCount() << " - Value = " << a3 << "." << std::endl;
			}
			else if (std::strcmp(m.AddressPattern(), "/test3") == 0){

				// example #3:
				// parse a variable argument format using the argument iterator
				// interface. this is where it is necessary to use
				// argument iterators instead of streams.
				// When messages may contain arguments of varying type, you can
				// use the argument iterator interface to query the types at
				// runtime. this is more flexible that the argument stream
				// interface, which requires each argument to have a fixed type

				if (arg->IsBool()){
					bool a = (arg++)->AsBoolUnchecked();
					std::cout << "received '/test3' message with bool argument: "
						<< a << "\n";
				}
				else if (arg->IsInt32()){
					int a = (arg++)->AsInt32Unchecked();
					std::cout << "received '/test3' message with int32 argument: "
						<< a << "\n";
				}
				else if (arg->IsFloat()){
					float a = (arg++)->AsFloatUnchecked();
					std::cout << "received '/test3' message with float argument: "
						<< a << "\n";
				}
				else if (arg->IsString()){
					const char *a = (arg++)->AsStringUnchecked();
					std::cout << "received '/test3' message with string argument: '"
						<< a << "'\n";
				}
				else{
					std::cout << "received '/test3' message with unexpected argument type\n";
				}

				if (arg != m.ArgumentsEnd())
					throw ExcessArgumentException();


			}
			else if (std::strcmp(m.AddressPattern(), "/no_arguments") == 0){

				args >> osc::EndMessage;
				std::cout << "received '/no_arguments' message\n";

			}
			else if (std::strcmp(m.AddressPattern(), "/a_bool") == 0){

				bool a;
				args >> a >> osc::EndMessage;
				std::cout << "received '/a_bool' message: " << a << "\n";

			}
			else if (std::strcmp(m.AddressPattern(), "/nil") == 0){

				std::cout << "received '/nil' message\n";

			}
			else if (std::strcmp(m.AddressPattern(), "/inf") == 0){

				std::cout << "received '/inf' message\n";

			}
			else if (std::strcmp(m.AddressPattern(), "/an_int") == 0){

				osc::int32 a;
				args >> a >> osc::EndMessage;
				std::cout << "received '/an_int' message: " << a << "\n";

			}
			else if (std::strcmp(m.AddressPattern(), "/a_float") == 0){

				float a;
				args >> a >> osc::EndMessage;
				std::cout << "received '/a_float' message: " << a << "\n";

			}
			else if (std::strcmp(m.AddressPattern(), "/a_char") == 0){

				char a;
				args >> a >> osc::EndMessage;
				char s[2] = { 0 };
				s[0] = a;
				std::cout << "received '/a_char' message: '" << s << "'\n";

			}
			else if (std::strcmp(m.AddressPattern(), "/an_rgba_color") == 0){

				osc::RgbaColor a;
				args >> a >> osc::EndMessage;
				std::cout << "received '/an_rgba_color' message: " << a.value << "\n";

			}
			else if (std::strcmp(m.AddressPattern(), "/a_midi_message") == 0){

				osc::MidiMessage a;
				args >> a >> osc::EndMessage;
				std::cout << "received '/a_midi_message' message: " << a.value << "\n";

			}
			else if (std::strcmp(m.AddressPattern(), "/an_int64") == 0){

				osc::int64 a;
				args >> a >> osc::EndMessage;
				std::cout << "received '/an_int64' message: " << a << "\n";

			}
			else if (std::strcmp(m.AddressPattern(), "/a_time_tag") == 0){

				osc::TimeTag a;
				args >> a >> osc::EndMessage;
				std::cout << "received '/a_time_tag' message: " << a.value << "\n";

			}
			else if (std::strcmp(m.AddressPattern(), "/a_double") == 0){

				double a;
				args >> a >> osc::EndMessage;
				std::cout << "received '/a_double' message: " << a << "\n";

			}
			else if (std::strcmp(m.AddressPattern(), "/a_string") == 0){

				const char *a;
				args >> a >> osc::EndMessage;
				std::cout << "received '/a_string' message: '" << a << "'\n";

			}
			else if (std::strcmp(m.AddressPattern(), "/a_symbol") == 0){

				osc::Symbol a;
				args >> a >> osc::EndMessage;
				std::cout << "received '/a_symbol' message: '" << a.value << "'\n";

			}
			else if (std::strcmp(m.AddressPattern(), "/a_blob") == 0){

				osc::Blob a;
				args >> a >> osc::EndMessage;
				std::cout << "received '/a_blob' message\n";

			}
			else{
				std::cout << "unrecognised address pattern: "
					<< m.AddressPattern() << "\n";
			}

			if (signalLastPush == false && signalPush == true && state == false)
			{
				INPUT key_S, key_P, key_I, key_N, key_SpaceBar, key_O, key_F, key_ENTER;

				// Pause for 5 seconds.
				//Sleep(500);

				// Set up a generic keyboard event.
				key_S.type = INPUT_KEYBOARD;
				key_S.ki.wScan = 0; // hardware scan code for key
				key_S.ki.time = 0;
				key_S.ki.dwExtraInfo = 0;

				key_P.type = INPUT_KEYBOARD;
				key_P.ki.wScan = 0; // hardware scan code for key
				key_P.ki.time = 0;
				key_P.ki.dwExtraInfo = 0;

				key_I.type = INPUT_KEYBOARD;
				key_I.ki.wScan = 0; // hardware scan code for key
				key_I.ki.time = 0;
				key_I.ki.dwExtraInfo = 0;

				key_N.type = INPUT_KEYBOARD;
				key_N.ki.wScan = 0; // hardware scan code for key
				key_N.ki.time = 0;
				key_N.ki.dwExtraInfo = 0;

				key_O.type = INPUT_KEYBOARD;
				key_O.ki.wScan = 0; // hardware scan code for key
				key_O.ki.time = 0;
				key_O.ki.dwExtraInfo = 0;

				key_F.type = INPUT_KEYBOARD;
				key_F.ki.wScan = 0; // hardware scan code for key
				key_F.ki.time = 0;
				key_F.ki.dwExtraInfo = 0;

				key_SpaceBar.type = INPUT_KEYBOARD;
				key_SpaceBar.ki.wScan = 0; // hardware scan code for key
				key_SpaceBar.ki.time = 0;
				key_SpaceBar.ki.dwExtraInfo = 0;

				key_ENTER.type = INPUT_KEYBOARD;
				key_ENTER.ki.wScan = 0; // hardware scan code for key
				key_ENTER.ki.time = 0;
				key_ENTER.ki.dwExtraInfo = 0;



				// Press the "s" key
				key_S.ki.wVk = 0x53; // virtual-key code for the "s" key
				key_S.ki.dwFlags = 0; // 0 for key press
				SendInput(1, &key_S, sizeof(INPUT));
				key_S.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
				SendInput(1, &key_S, sizeof(INPUT));

				// Press the "p" key
				key_P.ki.wVk = 0x50; // virtual-key code for the "p" key
				key_P.ki.dwFlags = 0; // 0 for key press
				SendInput(1, &key_P, sizeof(INPUT));
				key_P.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
				SendInput(1, &key_P, sizeof(INPUT));

				// Press the "i" key
				key_I.ki.wVk = 0x49; // virtual-key code for the "i" key
				key_I.ki.dwFlags = 0; // 0 for key press
				SendInput(1, &key_I, sizeof(INPUT));
				key_I.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
				SendInput(1, &key_I, sizeof(INPUT));

				// Press the "n" key
				key_N.ki.wVk = 0x4E; // virtual-key code for the "n" key
				key_N.ki.dwFlags = 0; // 0 for key press
				SendInput(1, &key_N, sizeof(INPUT));
				key_N.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
				SendInput(1, &key_N, sizeof(INPUT));

				// Press the "SpaceBar" key
				key_SpaceBar.ki.wVk = 0x20; // virtual-key code for the "SpaceBar" key
				key_SpaceBar.ki.dwFlags = 0; // 0 for key press
				SendInput(1, &key_SpaceBar, sizeof(INPUT));
				key_SpaceBar.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
				SendInput(1, &key_SpaceBar, sizeof(INPUT));

				// Press the "o" key
				key_O.ki.wVk = 0x4F; // virtual-key code for the "o" key
				key_O.ki.dwFlags = 0; // 0 for key press
				SendInput(1, &key_O, sizeof(INPUT));
				key_O.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
				SendInput(1, &key_O, sizeof(INPUT));

				// Press the "n" key
				key_N.ki.wVk = 0x4E; // virtual-key code for the "n" key
				key_N.ki.dwFlags = 0; // 0 for key press
				SendInput(1, &key_N, sizeof(INPUT));
				key_N.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
				SendInput(1, &key_N, sizeof(INPUT));

				// Press the "Enter" key
				key_ENTER.ki.wVk = 0x0D; // virtual-key code for the "Enter" key
				key_ENTER.ki.dwFlags = 0; // 0 for key press
				SendInput(1, &key_ENTER, sizeof(INPUT));
				key_ENTER.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
				SendInput(1, &key_ENTER, sizeof(INPUT));
				// Press the "Enter" key
				key_ENTER.ki.wVk = 0x0D; // virtual-key code for the "Enter" key
				key_ENTER.ki.dwFlags = 0; // 0 for key press
				SendInput(1, &key_ENTER, sizeof(INPUT));
				key_ENTER.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
				SendInput(1, &key_ENTER, sizeof(INPUT));

				state = !state;
			}
			else if (signalLastPush == false && signalPush == true && state == true)
			{
				INPUT key_S, key_P, key_I, key_N, key_SpaceBar, key_O, key_F, key_ENTER;

				// Pause for 5 seconds.
				//Sleep(5000);

				// Set up a generic keyboard event.
				key_S.type = INPUT_KEYBOARD;
				key_S.ki.wScan = 0; // hardware scan code for key
				key_S.ki.time = 0;
				key_S.ki.dwExtraInfo = 0;

				key_P.type = INPUT_KEYBOARD;
				key_P.ki.wScan = 0; // hardware scan code for key
				key_P.ki.time = 0;
				key_P.ki.dwExtraInfo = 0;

				key_I.type = INPUT_KEYBOARD;
				key_I.ki.wScan = 0; // hardware scan code for key
				key_I.ki.time = 0;
				key_I.ki.dwExtraInfo = 0;

				key_N.type = INPUT_KEYBOARD;
				key_N.ki.wScan = 0; // hardware scan code for key
				key_N.ki.time = 0;
				key_N.ki.dwExtraInfo = 0;

				key_O.type = INPUT_KEYBOARD;
				key_O.ki.wScan = 0; // hardware scan code for key
				key_O.ki.time = 0;
				key_O.ki.dwExtraInfo = 0;

				key_F.type = INPUT_KEYBOARD;
				key_F.ki.wScan = 0; // hardware scan code for key
				key_F.ki.time = 0;
				key_F.ki.dwExtraInfo = 0;

				key_SpaceBar.type = INPUT_KEYBOARD;
				key_SpaceBar.ki.wScan = 0; // hardware scan code for key
				key_SpaceBar.ki.time = 0;
				key_SpaceBar.ki.dwExtraInfo = 0;

				key_ENTER.type = INPUT_KEYBOARD;
				key_ENTER.ki.wScan = 0; // hardware scan code for key
				key_ENTER.ki.time = 0;
				key_ENTER.ki.dwExtraInfo = 0;



				// Press the "s" key
				key_S.ki.wVk = 0x53; // virtual-key code for the "s" key
				key_S.ki.dwFlags = 0; // 0 for key press
				SendInput(1, &key_S, sizeof(INPUT));
				key_S.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
				SendInput(1, &key_S, sizeof(INPUT));

				// Press the "p" key
				key_P.ki.wVk = 0x50; // virtual-key code for the "p" key
				key_P.ki.dwFlags = 0; // 0 for key press
				SendInput(1, &key_P, sizeof(INPUT));
				key_P.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
				SendInput(1, &key_P, sizeof(INPUT));

				// Press the "i" key
				key_I.ki.wVk = 0x49; // virtual-key code for the "i" key
				key_I.ki.dwFlags = 0; // 0 for key press
				SendInput(1, &key_I, sizeof(INPUT));
				key_I.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
				SendInput(1, &key_I, sizeof(INPUT));

				// Press the "n" key
				key_N.ki.wVk = 0x4E; // virtual-key code for the "n" key
				key_N.ki.dwFlags = 0; // 0 for key press
				SendInput(1, &key_N, sizeof(INPUT));
				key_N.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
				SendInput(1, &key_N, sizeof(INPUT));

				// Press the "SpaceBar" key
				key_SpaceBar.ki.wVk = 0x20; // virtual-key code for the "SpaceBar" key
				key_SpaceBar.ki.dwFlags = 0; // 0 for key press
				SendInput(1, &key_SpaceBar, sizeof(INPUT));
				key_SpaceBar.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
				SendInput(1, &key_SpaceBar, sizeof(INPUT));

				// Press the "o" key
				key_O.ki.wVk = 0x4F; // virtual-key code for the "o" key
				key_O.ki.dwFlags = 0; // 0 for key press
				SendInput(1, &key_O, sizeof(INPUT));
				key_O.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
				SendInput(1, &key_O, sizeof(INPUT));

				// Press the "f" key
				key_F.ki.wVk = 0x46; // virtual-key code for the "f" key
				key_F.ki.dwFlags = 0; // 0 for key press
				SendInput(1, &key_F, sizeof(INPUT));
				key_F.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
				SendInput(1, &key_F, sizeof(INPUT));

				// Press the "f" key
				key_F.ki.wVk = 0x46; // virtual-key code for the "f" key
				key_F.ki.dwFlags = 0; // 0 for key press
				SendInput(1, &key_F, sizeof(INPUT));
				key_F.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
				SendInput(1, &key_F, sizeof(INPUT));

				// Press the "Enter" key
				key_ENTER.ki.wVk = 0x0D; // virtual-key code for the "Enter" key
				key_ENTER.ki.dwFlags = 0; // 0 for key press
				SendInput(1, &key_ENTER, sizeof(INPUT));
				key_ENTER.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
				SendInput(1, &key_ENTER, sizeof(INPUT));
				// Press the "Enter" key
				key_ENTER.ki.wVk = 0x0D; // virtual-key code for the "Enter" key
				key_ENTER.ki.dwFlags = 0; // 0 for key press
				SendInput(1, &key_ENTER, sizeof(INPUT));
				key_ENTER.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
				SendInput(1, &key_ENTER, sizeof(INPUT));

				state = !state;
			}

			signalLastPush = signalPush;


		}
		catch (osc::Exception& e){
			// any parsing errors such as unexpected argument types, or 
			// missing arguments get thrown as exceptions.
			std::cout << "error while parsing message: "
				<< m.AddressPattern() << ": " << e.what() << "\n";
		}
	}
};

int main(int argc, char* argv[])
{
	(void)argc; // suppress unused parameter warnings
	(void)argv; // suppress unused parameter warnings

	ExamplePacketListener listener;
	UdpListeningReceiveSocket s(
		IpEndpointName(IpEndpointName::ANY_ADDRESS, PORT),
		&listener);

	std::cout << "press ctrl-c to end\n";

	s.RunUntilSigInt();

	return 0;
}

