#include <fstream>

int checkPresence() {
    std::ofstream oFile;
    //���������½��ļ�
    oFile.open("C:\\Config.json", std::ios::app);
    if (!oFile)  //true��˵���ļ��򿪳���
        return -1;
    else {
        oFile.close();
        return 1;
    }
        
    return 0;
}