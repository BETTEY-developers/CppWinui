#pragma once

#define WinUINamespace Microsoft
#define WinUINamespace1(a) WinUINamespace::a
#define WinUINamespace2(a, b) WinUINamespace1(a)::b
#define WinUINamespace3(a, b, c) WinUINamespace2(a, b)::c
#define WinUINamespace4(a, b, c, d) WinUINamespace3(a, b, c)::d
#define WinUINamespace5(a, b, c, d, e) WinUINamespace4(a, b, c, d)::e


#define Bindable \
public:\
event_token PropertyChanged(WinUINamespace3(UI, Xaml, Data)::PropertyChangedEventHandler const& value)\
{\
    return m_propertyChanged.add(value);\
}\
void PropertyChanged(event_token const& token)\
{\
    m_propertyChanged.remove(token);\
}\
private:\
event<WinUINamespace3(UI, Xaml, Data)::PropertyChangedEventHandler> m_propertyChanged;\
void RaisePropertyChanged(hstring const& propertyName)\
{\
    m_propertyChanged(*this, WinUINamespace3(UI, Xaml, Data)::PropertyChangedEventArgs(propertyName));\
}

#define UpdateValue(propertyName, var, value) \
if (var != value)\
{\
    var = value;\
    RaisePropertyChanged(propertyName);\
}

#define FactoryDefinition(className) \
namespace winrt::CppWinui::factory_implementation\
{\
    struct className : className##T<className, implementation::className>\
    {\
    };\
}

#define _PropertyName(name) m_##name

#define _InnerPropertyDeclaration(type, name) \
private:\
type _PropertyName(name);

#define NotifyChangedProperty(type, name) \
_InnerPropertyDeclaration(type, name)\
public:\
    type name()\
    {\
        return _PropertyName(name);\
    }\
    void name(type value)\
    {\
        UpdateValue(L#name, _PropertyName(name), value);\
    }\

#define Property(type, name)\
_InnerPropertyDeclaration(type, name)\
public:\
    type name()\
    {\
        return _PropertyName(name);\
    }\
    void name(type value)\
    {\
        _PropertyName(name) = value;\
    }\

#define ReadonlyProperty(type, name)\
_InnerPropertyDeclaration(type, name)\
public:\
    type name()\
    {\
        return _PropertyName(name);\
    }\

#define SetPropertyValue(name, value) this->_PropertyName(name) = value;