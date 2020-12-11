#include <iostream>
#include <json/json.h>

using namespace std;



int main()
{
    std::string strValue = "{\"name\":\"json\",\"array\":[{\"cpp\":\"jsoncpp\"},{\"java\":\"jsoninjava\"},{\"php\":\"support\"}]}";

    Json::Reader reader;
    Json::Value value;

    if (reader.parse(strValue, value))
    {
        std::string out = value["name"].asString();
        std::cout << out << std::endl;
        const Json::Value arrayObj = value["array"];
        for (unsigned int i = 0; i < arrayObj.size(); i++)
        {
            if (!arrayObj[i].isMember("cpp"))
                continue;
            out = arrayObj[i]["cpp"].asString();
            std::cout << out;
            if (i != (arrayObj.size() - 1))
                std::cout << std::endl;
        }
    }
    return 0;
}