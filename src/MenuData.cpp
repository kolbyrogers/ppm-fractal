#include "MenuData.h"

MenuData::MenuData()
{
    // empty constructor
}

void MenuData::addAction(const std::string &name, ActionFunctionType func, const std::string &description)
{
    mNames.push_back(name);
    mActions[name] = func;
    mDescriptions[name] = description;
}

const std::vector<std::string> &MenuData::getNames() const
{
    return mNames;
}

ActionFunctionType MenuData::getFunction(const std::string &name)
{
    return mActions.count(name) == 0 ? 0 : mActions[name];
}

const std::string &MenuData::getDescription(const std::string &name)
{
    static std::string empty = "";
    return mDescriptions.count(name) == 0 ? empty : mDescriptions[name];
}