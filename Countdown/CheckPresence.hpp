#include <fstream>

int checkPresence() {
    std::ofstream oFile;
    //不存在则新建文件
    oFile.open("C:\\Config.json", std::ios::app);
    if (!oFile)  //true则说明文件打开出错
        return -1;
    else {
        oFile.close();
        return 1;
    }
        
    return 0;
}