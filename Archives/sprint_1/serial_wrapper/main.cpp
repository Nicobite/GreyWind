#include <iostream>
#include "serial_wrapper.hpp"

using namespace std;

int main(int argc,char * argv[]){
    char toSend = 'd';
    if (argc > 1){
        toSend = *argv[1];
    }
    cout << "Hello World!\n";
    cout << toSend << endl;
    SerialDevice testDevice("/dev/ttyACM0",B57600,0,0);
    testDevice.writeChar(toSend);
    cout << "sending a char...\n";
    usleep ((7 + 25) * 100);
    char ret = testDevice.readChar();
    cout << ret << endl;
    return 0;
}

