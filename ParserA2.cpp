#include "json.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <direct.h>
#include <windows.h>
#include <fstream>
#include <cstdint>
#include <filesystem>
using json = nlohmann::json;
using namespace std;

int main() {
    cout << "Program writed by DarkV" << endl;
    cout << "The author is not responsible for the programand its use.The user is fully responsible for his actions." << endl;
    cout << "If you press the button next, you confirm the aboveand carry full responsibility for your actions." << endl;
    system("PAUSE");
    system("cls");
    cout << "Tested on windows 10 [Version 10.0.18363.657]" << endl;
    cout << "Name of apiticket file - response_content.json" << endl;
    Sleep(1000);
    ifstream ifileA("response_content.json");
    if (!ifileA)
    {
        cout << "Response_content.json don't finded!" << endl;
        system("PAUSE");
    }
    else
    {
        ifstream i("response_content.json");
        json j; i >> j;
        string responseString(j.dump());
        json responseJson(json::parse(responseString));
        json object(responseJson["result"]);
        json data(object["data"]);
        json entities(data["entities"]);
        int g = 0; // amout of files in api_ticket all .tar archive 
        while (true)
        {
            string type = entities[g]["type"];
            if (type == "tar") {
                cout << "Amout of files:";
                g = g - 1; // -1 .tar type
                cout << g << endl;
                break;
            }
            else g++;
        }
            int o = 0;
            while (o != g) // hash = name file and type = type of file 
            {
                string hash = entities[o]["hash"];
                string type = entities[o]["type"];
                string FullName = hash + "." + type; // name + format of file
                rename(hash.c_str(), FullName.c_str());
                cout << FullName << endl;
                o++;
            }
            system("PAUSE");
       
    }
}