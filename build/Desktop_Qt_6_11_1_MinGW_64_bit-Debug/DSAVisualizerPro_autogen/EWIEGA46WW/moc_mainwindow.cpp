/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../mainwindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.11.1. It"
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
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto MainWindow::qt_create_metaobjectdata<qt_meta_tag_ZN10MainWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "MainWindow",
        "on_btnGenerate_clicked",
        "",
        "on_btnStart_clicked",
        "on_btnPause_clicked",
        "on_btnReset_clicked",
        "on_speedSlider_valueChanged",
        "value",
        "bubbleSortStep",
        "selectionSortStep",
        "insertionSortStep",
        "mergeSortStep",
        "quickSortStep",
        "heapSortStep",
        "linearSearchStep",
        "binarySearchStep",
        "dfsStep",
        "bfsStep",
        "preorderStep",
        "inorderStep",
        "postorderStep",
        "levelOrderStep",
        "dijkstraStep",
        "primStep",
        "kruskalStep",
        "topologicalSortStep",
        "generateQuickSortOperations",
        "std::vector<int>&",
        "tempArr",
        "low",
        "high",
        "partitionOperations",
        "generateMergeSortOperations",
        "left",
        "right",
        "mergeOperationHelper",
        "mid",
        "generateHeapOperations",
        "heapifyOperations",
        "n",
        "i",
        "startSelectedAlgorithm",
        "generateRandomBars",
        "drawBars"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_btnGenerate_clicked'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnStart_clicked'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnPause_clicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnReset_clicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_speedSlider_valueChanged'
        QtMocHelpers::SlotData<void(int)>(6, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Slot 'bubbleSortStep'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'selectionSortStep'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'insertionSortStep'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'mergeSortStep'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'quickSortStep'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'heapSortStep'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'linearSearchStep'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'binarySearchStep'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'dfsStep'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'bfsStep'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'preorderStep'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'inorderStep'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'postorderStep'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'levelOrderStep'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'dijkstraStep'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'primStep'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'kruskalStep'
        QtMocHelpers::SlotData<void()>(24, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'topologicalSortStep'
        QtMocHelpers::SlotData<void()>(25, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'generateQuickSortOperations'
        QtMocHelpers::SlotData<void(std::vector<int> &, int, int)>(26, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 27, 28 }, { QMetaType::Int, 29 }, { QMetaType::Int, 30 },
        }}),
        // Slot 'partitionOperations'
        QtMocHelpers::SlotData<int(std::vector<int> &, int, int)>(31, 2, QMC::AccessPrivate, QMetaType::Int, {{
            { 0x80000000 | 27, 28 }, { QMetaType::Int, 29 }, { QMetaType::Int, 30 },
        }}),
        // Slot 'generateMergeSortOperations'
        QtMocHelpers::SlotData<void(std::vector<int> &, int, int)>(32, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 27, 28 }, { QMetaType::Int, 33 }, { QMetaType::Int, 34 },
        }}),
        // Slot 'mergeOperationHelper'
        QtMocHelpers::SlotData<void(std::vector<int> &, int, int, int)>(35, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 27, 28 }, { QMetaType::Int, 33 }, { QMetaType::Int, 36 }, { QMetaType::Int, 34 },
        }}),
        // Slot 'generateHeapOperations'
        QtMocHelpers::SlotData<void(std::vector<int> &)>(37, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 27, 28 },
        }}),
        // Slot 'heapifyOperations'
        QtMocHelpers::SlotData<void(std::vector<int> &, int, int)>(38, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 27, 28 }, { QMetaType::Int, 39 }, { QMetaType::Int, 40 },
        }}),
        // Slot 'startSelectedAlgorithm'
        QtMocHelpers::SlotData<void()>(41, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'generateRandomBars'
        QtMocHelpers::SlotData<void()>(42, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'drawBars'
        QtMocHelpers::SlotData<void()>(43, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MainWindow, qt_meta_tag_ZN10MainWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10MainWindowE_t>.metaTypes,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_btnGenerate_clicked(); break;
        case 1: _t->on_btnStart_clicked(); break;
        case 2: _t->on_btnPause_clicked(); break;
        case 3: _t->on_btnReset_clicked(); break;
        case 4: _t->on_speedSlider_valueChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->bubbleSortStep(); break;
        case 6: _t->selectionSortStep(); break;
        case 7: _t->insertionSortStep(); break;
        case 8: _t->mergeSortStep(); break;
        case 9: _t->quickSortStep(); break;
        case 10: _t->heapSortStep(); break;
        case 11: _t->linearSearchStep(); break;
        case 12: _t->binarySearchStep(); break;
        case 13: _t->dfsStep(); break;
        case 14: _t->bfsStep(); break;
        case 15: _t->preorderStep(); break;
        case 16: _t->inorderStep(); break;
        case 17: _t->postorderStep(); break;
        case 18: _t->levelOrderStep(); break;
        case 19: _t->dijkstraStep(); break;
        case 20: _t->primStep(); break;
        case 21: _t->kruskalStep(); break;
        case 22: _t->topologicalSortStep(); break;
        case 23: _t->generateQuickSortOperations((*reinterpret_cast<std::add_pointer_t<std::vector<int>&>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[3]))); break;
        case 24: { int _r = _t->partitionOperations((*reinterpret_cast<std::add_pointer_t<std::vector<int>&>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[3])));
            if (_a[0]) *reinterpret_cast<int*>(_a[0]) = std::move(_r); }  break;
        case 25: _t->generateMergeSortOperations((*reinterpret_cast<std::add_pointer_t<std::vector<int>&>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[3]))); break;
        case 26: _t->mergeOperationHelper((*reinterpret_cast<std::add_pointer_t<std::vector<int>&>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[4]))); break;
        case 27: _t->generateHeapOperations((*reinterpret_cast<std::add_pointer_t<std::vector<int>&>>(_a[1]))); break;
        case 28: _t->heapifyOperations((*reinterpret_cast<std::add_pointer_t<std::vector<int>&>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[3]))); break;
        case 29: _t->startSelectedAlgorithm(); break;
        case 30: _t->generateRandomBars(); break;
        case 31: _t->drawBars(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 32)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 32;
    }
    return _id;
}
QT_WARNING_POP
