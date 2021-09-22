#ifndef _MENUDATA_H
#define _MENUDATA_H_

#include <iostream>
#include <vector>
#include <map>
#include "ActionData.h"

typedef void (*ActionFunctionType)(ActionData &action_data);

class MenuData
{
    // Data Members:
    std::vector<std::string> mNames;
    std::map<std::string, ActionFunctionType> mActions;
    std::map<std::string, std::string> mDescriptions;

    // Methods:
    MenuData();
    void addAction(const std::string &name, ActionFunctionType func, const std::string &description);
    const std::vector<std::string> &getNames() const;
    ActionFunctionType getFunction(const std::string &name);
    const std::string &getDescription(const std::string &name);
};

#endif
