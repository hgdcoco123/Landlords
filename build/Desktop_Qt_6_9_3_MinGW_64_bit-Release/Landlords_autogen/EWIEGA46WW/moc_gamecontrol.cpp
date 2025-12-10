/****************************************************************************
** Meta object code from reading C++ file 'gamecontrol.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../gamecontrol.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamecontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN11GameControlE_t {};
} // unnamed namespace

template <> constexpr inline auto GameControl::qt_create_metaobjectdata<qt_meta_tag_ZN11GameControlE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "GameControl",
        "playerStatusChanged",
        "",
        "Player*",
        "player",
        "PlayerStatus",
        "status",
        "notifyGrabLordBet",
        "bet",
        "flag",
        "gameStatusChanged",
        "GameStatus",
        "notifyPlayHand",
        "Cards",
        "card",
        "pendingInfo"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'playerStatusChanged'
        QtMocHelpers::SignalData<void(Player *, enum PlayerStatus)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 5, 6 },
        }}),
        // Signal 'notifyGrabLordBet'
        QtMocHelpers::SignalData<void(Player *, int, bool)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::Int, 8 }, { QMetaType::Bool, 9 },
        }}),
        // Signal 'gameStatusChanged'
        QtMocHelpers::SignalData<void(enum GameStatus)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 11, 6 },
        }}),
        // Signal 'notifyPlayHand'
        QtMocHelpers::SignalData<void(Player *, Cards)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 13, 14 },
        }}),
        // Signal 'pendingInfo'
        QtMocHelpers::SignalData<void(Player *, Cards)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 13, 14 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<GameControl, qt_meta_tag_ZN11GameControlE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject GameControl::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11GameControlE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11GameControlE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11GameControlE_t>.metaTypes,
    nullptr
} };

void GameControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<GameControl *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->playerStatusChanged((*reinterpret_cast< std::add_pointer_t<Player*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<enum PlayerStatus>>(_a[2]))); break;
        case 1: _t->notifyGrabLordBet((*reinterpret_cast< std::add_pointer_t<Player*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 2: _t->gameStatusChanged((*reinterpret_cast< std::add_pointer_t<enum GameStatus>>(_a[1]))); break;
        case 3: _t->notifyPlayHand((*reinterpret_cast< std::add_pointer_t<Player*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Cards>>(_a[2]))); break;
        case 4: _t->pendingInfo((*reinterpret_cast< std::add_pointer_t<Player*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Cards>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Player* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Player* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Cards >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Player* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Cards >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Player* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (GameControl::*)(Player * , PlayerStatus )>(_a, &GameControl::playerStatusChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (GameControl::*)(Player * , int , bool )>(_a, &GameControl::notifyGrabLordBet, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (GameControl::*)(GameStatus )>(_a, &GameControl::gameStatusChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (GameControl::*)(Player * , Cards )>(_a, &GameControl::notifyPlayHand, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (GameControl::*)(Player * , Cards )>(_a, &GameControl::pendingInfo, 4))
            return;
    }
}

const QMetaObject *GameControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11GameControlE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GameControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void GameControl::playerStatusChanged(Player * _t1, PlayerStatus _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void GameControl::notifyGrabLordBet(Player * _t1, int _t2, bool _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2, _t3);
}

// SIGNAL 2
void GameControl::gameStatusChanged(GameStatus _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void GameControl::notifyPlayHand(Player * _t1, Cards _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2);
}

// SIGNAL 4
void GameControl::pendingInfo(Player * _t1, Cards _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1, _t2);
}
QT_WARNING_POP
