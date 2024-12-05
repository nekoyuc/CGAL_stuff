/****************************************************************************
** Meta object code from reading C++ file 'qglviewer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../opt/homebrew/include/CGAL/Qt/qglviewer.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qglviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSCGALSCOPEQGLViewerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSCGALSCOPEQGLViewerENDCLASS = QtMocHelpers::stringData(
    "CGAL::QGLViewer",
    "viewerInitialized",
    "",
    "drawNeeded",
    "drawFinished",
    "automatic",
    "animateNeeded",
    "helpRequired",
    "axisIsDrawnChanged",
    "drawn",
    "gridIsDrawnChanged",
    "FPSIsDisplayedChanged",
    "displayed",
    "textIsEnabledChanged",
    "enabled",
    "cameraIsEditedChanged",
    "edited",
    "pointSelected",
    "const QMouseEvent*",
    "e",
    "mouseGrabberChanged",
    "qglviewer::MouseGrabber*",
    "mouseGrabber",
    "contextIsDestroyed",
    "needNewContext",
    "setAxisIsDrawn",
    "draw",
    "setGridIsDrawn",
    "setFPSIsDisplayed",
    "display",
    "setTextIsEnabled",
    "enable",
    "setCameraIsEdited",
    "edit",
    "toggleAxisIsDrawn",
    "toggleGridIsDrawn",
    "toggleFPSIsDisplayed",
    "toggleTextIsEnabled",
    "toggleCameraIsEdited",
    "setBackgroundColor",
    "color",
    "setForegroundColor",
    "setSceneRadius",
    "radius",
    "setSceneCenter",
    "qglviewer::Vec",
    "center",
    "setSceneBoundingBox",
    "min",
    "max",
    "showEntireScene",
    "setCamera",
    "qglviewer::Camera*",
    "camera",
    "setManipulatedFrame",
    "qglviewer::ManipulatedFrame*",
    "frame",
    "setMouseGrabber",
    "setFullScreen",
    "fullScreen",
    "toggleFullScreen",
    "toggleCameraMode",
    "copyBufferToTexture",
    "GLint",
    "GLenum",
    "setAnimationPeriod",
    "period",
    "startAnimation",
    "stopAnimation",
    "animate",
    "toggleAnimation",
    "help",
    "aboutQGLViewer",
    "select",
    "event",
    "point",
    "setSelectBufferSize",
    "size",
    "setSelectRegionWidth",
    "width",
    "setSelectRegionHeight",
    "height",
    "setSelectedName",
    "id",
    "setShortcut",
    "qglviewer::KeyboardAction",
    "action",
    "QKeyCombination",
    "key",
    "::Qt::Modifier",
    "modifier",
    "::Qt::Key",
    "setKeyDescription",
    "description",
    "::Qt::KeyboardModifier",
    "clearShortcuts",
    "setPathKey",
    "index",
    "setPlayPathKeyboardModifiers",
    "::Qt::KeyboardModifiers",
    "modifiers",
    "setAddKeyFrameKeyboardModifiers",
    "setMouseBinding",
    "::Qt::MouseButton",
    "buttons",
    "qglviewer::MouseHandler",
    "handler",
    "qglviewer::MouseAction",
    "withConstraint",
    "button",
    "qglviewer::ClickAction",
    "doubleClick",
    "::Qt::MouseButtons",
    "buttonsBefore",
    "setWheelBinding",
    "setMouseBindingDescription",
    "clearMouseBindings",
    "resetVisualHints",
    "delayedFullScreen",
    "hideMessage"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCGALSCOPEQGLViewerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      91,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  560,    2, 0x06,    1 /* Public */,
       3,    0,  561,    2, 0x06,    2 /* Public */,
       4,    1,  562,    2, 0x06,    3 /* Public */,
       6,    0,  565,    2, 0x06,    5 /* Public */,
       7,    0,  566,    2, 0x06,    6 /* Public */,
       8,    1,  567,    2, 0x06,    7 /* Public */,
      10,    1,  570,    2, 0x06,    9 /* Public */,
      11,    1,  573,    2, 0x06,   11 /* Public */,
      13,    1,  576,    2, 0x06,   13 /* Public */,
      15,    1,  579,    2, 0x06,   15 /* Public */,
      17,    1,  582,    2, 0x06,   17 /* Public */,
      20,    1,  585,    2, 0x06,   19 /* Public */,
      23,    0,  588,    2, 0x06,   21 /* Public */,
      24,    0,  589,    2, 0x06,   22 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      25,    1,  590,    2, 0x0a,   23 /* Public */,
      25,    0,  593,    2, 0x2a,   25 /* Public | MethodCloned */,
      27,    1,  594,    2, 0x0a,   26 /* Public */,
      27,    0,  597,    2, 0x2a,   28 /* Public | MethodCloned */,
      28,    1,  598,    2, 0x0a,   29 /* Public */,
      28,    0,  601,    2, 0x2a,   31 /* Public | MethodCloned */,
      30,    1,  602,    2, 0x0a,   32 /* Public */,
      30,    0,  605,    2, 0x2a,   34 /* Public | MethodCloned */,
      32,    1,  606,    2, 0x0a,   35 /* Public */,
      32,    0,  609,    2, 0x2a,   37 /* Public | MethodCloned */,
      34,    0,  610,    2, 0x0a,   38 /* Public */,
      35,    0,  611,    2, 0x0a,   39 /* Public */,
      36,    0,  612,    2, 0x0a,   40 /* Public */,
      37,    0,  613,    2, 0x0a,   41 /* Public */,
      38,    0,  614,    2, 0x0a,   42 /* Public */,
      39,    1,  615,    2, 0x0a,   43 /* Public */,
      41,    1,  618,    2, 0x0a,   45 /* Public */,
      42,    1,  621,    2, 0x0a,   47 /* Public */,
      44,    1,  624,    2, 0x0a,   49 /* Public */,
      47,    2,  627,    2, 0x0a,   51 /* Public */,
      50,    0,  632,    2, 0x0a,   54 /* Public */,
      51,    1,  633,    2, 0x0a,   55 /* Public */,
      54,    1,  636,    2, 0x0a,   57 /* Public */,
      57,    1,  639,    2, 0x0a,   59 /* Public */,
      58,    1,  642,    2, 0x0a,   61 /* Public */,
      58,    0,  645,    2, 0x2a,   63 /* Public | MethodCloned */,
      60,    0,  646,    2, 0x0a,   64 /* Public */,
      61,    0,  647,    2, 0x0a,   65 /* Public */,
      62,    2,  648,    2, 0x0a,   66 /* Public */,
      62,    1,  653,    2, 0x2a,   69 /* Public | MethodCloned */,
      65,    1,  656,    2, 0x0a,   71 /* Public */,
      67,    0,  659,    2, 0x0a,   73 /* Public */,
      68,    0,  660,    2, 0x0a,   74 /* Public */,
      69,    0,  661,    2, 0x0a,   75 /* Public */,
      70,    0,  662,    2, 0x0a,   76 /* Public */,
      71,    0,  663,    2, 0x0a,   77 /* Public */,
      72,    0,  664,    2, 0x0a,   78 /* Public */,
      73,    1,  665,    2, 0x0a,   79 /* Public */,
      73,    1,  668,    2, 0x0a,   81 /* Public */,
      76,    1,  671,    2, 0x0a,   83 /* Public */,
      78,    1,  674,    2, 0x0a,   85 /* Public */,
      80,    1,  677,    2, 0x0a,   87 /* Public */,
      82,    1,  680,    2, 0x0a,   89 /* Public */,
      84,    2,  683,    2, 0x0a,   91 /* Public */,
      84,    3,  688,    2, 0x0a,   94 /* Public */,
      92,    2,  695,    2, 0x0a,   98 /* Public */,
      92,    3,  700,    2, 0x0a,  101 /* Public */,
      92,    3,  707,    2, 0x0a,  105 /* Public */,
      95,    0,  714,    2, 0x0a,  109 /* Public */,
      96,    2,  715,    2, 0x0a,  110 /* Public */,
      96,    1,  720,    2, 0x2a,  113 /* Public | MethodCloned */,
      98,    1,  723,    2, 0x0a,  115 /* Public */,
     101,    1,  726,    2, 0x0a,  117 /* Public */,
     102,    5,  729,    2, 0x0a,  119 /* Public */,
     102,    4,  740,    2, 0x2a,  125 /* Public | MethodCloned */,
     102,    5,  749,    2, 0x0a,  130 /* Public */,
     102,    4,  760,    2, 0x2a,  136 /* Public | MethodCloned */,
     102,    3,  769,    2, 0x2a,  141 /* Public | MethodCloned */,
     114,    4,  776,    2, 0x0a,  145 /* Public */,
     114,    3,  785,    2, 0x2a,  150 /* Public | MethodCloned */,
     115,    5,  792,    2, 0x0a,  154 /* Public */,
     115,    4,  803,    2, 0x2a,  160 /* Public | MethodCloned */,
     115,    3,  812,    2, 0x2a,  165 /* Public | MethodCloned */,
     102,    6,  819,    2, 0x0a,  169 /* Public */,
     102,    5,  832,    2, 0x2a,  176 /* Public | MethodCloned */,
     102,    6,  843,    2, 0x0a,  182 /* Public */,
     102,    5,  856,    2, 0x2a,  189 /* Public | MethodCloned */,
     102,    4,  867,    2, 0x2a,  195 /* Public | MethodCloned */,
     114,    5,  876,    2, 0x0a,  200 /* Public */,
     114,    4,  887,    2, 0x2a,  206 /* Public | MethodCloned */,
     115,    6,  896,    2, 0x0a,  211 /* Public */,
     115,    5,  909,    2, 0x2a,  218 /* Public | MethodCloned */,
     115,    4,  920,    2, 0x2a,  224 /* Public | MethodCloned */,
     116,    0,  929,    2, 0x0a,  229 /* Public */,
     117,    0,  930,    2, 0x0a,  230 /* Public */,
     118,    0,  931,    2, 0x08,  231 /* Private */,
     119,    0,  932,    2, 0x08,  232 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   29,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   31,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   33,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor,   40,
    QMetaType::Void, QMetaType::QColor,   40,
    QMetaType::Void, QMetaType::QReal,   43,
    QMetaType::Void, 0x80000000 | 45,   46,
    QMetaType::Void, 0x80000000 | 45, 0x80000000 | 45,   48,   49,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 52,   53,
    QMetaType::Void, 0x80000000 | 55,   56,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, QMetaType::Bool,   59,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 63, 0x80000000 | 64,    2,    2,
    QMetaType::Void, 0x80000000 | 63,    2,
    QMetaType::Void, QMetaType::Int,   66,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   74,
    QMetaType::Void, QMetaType::QPoint,   75,
    QMetaType::Void, QMetaType::Int,   77,
    QMetaType::Void, QMetaType::Int,   79,
    QMetaType::Void, QMetaType::Int,   81,
    QMetaType::Void, QMetaType::Int,   83,
    QMetaType::Void, 0x80000000 | 85, 0x80000000 | 87,   86,   88,
    QMetaType::Void, 0x80000000 | 85, 0x80000000 | 89, 0x80000000 | 91,   86,   90,   88,
    QMetaType::Void, 0x80000000 | 87, QMetaType::QString,   88,   93,
    QMetaType::Void, 0x80000000 | 94, 0x80000000 | 91, QMetaType::QString,   90,   88,   93,
    QMetaType::Void, 0x80000000 | 89, 0x80000000 | 91, QMetaType::QString,   90,   88,   93,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::UInt,   88,   97,
    QMetaType::Void, QMetaType::Int,   88,
    QMetaType::Void, 0x80000000 | 99,  100,
    QMetaType::Void, 0x80000000 | 99,  100,
    QMetaType::Void, 0x80000000 | 99, 0x80000000 | 103, 0x80000000 | 105, 0x80000000 | 107, QMetaType::Bool,  100,  104,  106,   86,  108,
    QMetaType::Void, 0x80000000 | 99, 0x80000000 | 103, 0x80000000 | 105, 0x80000000 | 107,  100,  104,  106,   86,
    QMetaType::Void, 0x80000000 | 99, 0x80000000 | 103, 0x80000000 | 110, QMetaType::Bool, 0x80000000 | 112,  100,  109,   86,  111,  113,
    QMetaType::Void, 0x80000000 | 99, 0x80000000 | 103, 0x80000000 | 110, QMetaType::Bool,  100,  109,   86,  111,
    QMetaType::Void, 0x80000000 | 99, 0x80000000 | 103, 0x80000000 | 110,  100,  109,   86,
    QMetaType::Void, 0x80000000 | 99, 0x80000000 | 105, 0x80000000 | 107, QMetaType::Bool,  100,  106,   86,  108,
    QMetaType::Void, 0x80000000 | 99, 0x80000000 | 105, 0x80000000 | 107,  100,  106,   86,
    QMetaType::Void, 0x80000000 | 99, 0x80000000 | 103, QMetaType::QString, QMetaType::Bool, 0x80000000 | 112,  100,  109,   93,  111,  113,
    QMetaType::Void, 0x80000000 | 99, 0x80000000 | 103, QMetaType::QString, QMetaType::Bool,  100,  109,   93,  111,
    QMetaType::Void, 0x80000000 | 99, 0x80000000 | 103, QMetaType::QString,  100,  109,   93,
    QMetaType::Void, 0x80000000 | 91, 0x80000000 | 99, 0x80000000 | 103, 0x80000000 | 105, 0x80000000 | 107, QMetaType::Bool,   88,  100,  104,  106,   86,  108,
    QMetaType::Void, 0x80000000 | 91, 0x80000000 | 99, 0x80000000 | 103, 0x80000000 | 105, 0x80000000 | 107,   88,  100,  104,  106,   86,
    QMetaType::Void, 0x80000000 | 91, 0x80000000 | 99, 0x80000000 | 103, 0x80000000 | 110, QMetaType::Bool, 0x80000000 | 112,   88,  100,  109,   86,  111,  113,
    QMetaType::Void, 0x80000000 | 91, 0x80000000 | 99, 0x80000000 | 103, 0x80000000 | 110, QMetaType::Bool,   88,  100,  109,   86,  111,
    QMetaType::Void, 0x80000000 | 91, 0x80000000 | 99, 0x80000000 | 103, 0x80000000 | 110,   88,  100,  109,   86,
    QMetaType::Void, 0x80000000 | 91, 0x80000000 | 99, 0x80000000 | 105, 0x80000000 | 107, QMetaType::Bool,   88,  100,  106,   86,  108,
    QMetaType::Void, 0x80000000 | 91, 0x80000000 | 99, 0x80000000 | 105, 0x80000000 | 107,   88,  100,  106,   86,
    QMetaType::Void, 0x80000000 | 91, 0x80000000 | 99, 0x80000000 | 103, QMetaType::QString, QMetaType::Bool, 0x80000000 | 112,   88,  100,  109,   93,  111,  113,
    QMetaType::Void, 0x80000000 | 91, 0x80000000 | 99, 0x80000000 | 103, QMetaType::QString, QMetaType::Bool,   88,  100,  109,   93,  111,
    QMetaType::Void, 0x80000000 | 91, 0x80000000 | 99, 0x80000000 | 103, QMetaType::QString,   88,  100,  109,   93,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject CGAL::QGLViewer::staticMetaObject = { {
    QMetaObject::SuperData::link<QOpenGLWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSCGALSCOPEQGLViewerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCGALSCOPEQGLViewerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCGALSCOPEQGLViewerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QGLViewer, std::true_type>,
        // method 'viewerInitialized'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'drawNeeded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'drawFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'animateNeeded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'helpRequired'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'axisIsDrawnChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'gridIsDrawnChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'FPSIsDisplayedChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'textIsEnabledChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'cameraIsEditedChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'pointSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QMouseEvent *, std::false_type>,
        // method 'mouseGrabberChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::MouseGrabber *, std::false_type>,
        // method 'contextIsDestroyed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'needNewContext'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setAxisIsDrawn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setAxisIsDrawn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setGridIsDrawn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setGridIsDrawn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setFPSIsDisplayed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setFPSIsDisplayed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setTextIsEnabled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setTextIsEnabled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setCameraIsEdited'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setCameraIsEdited'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'toggleAxisIsDrawn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'toggleGridIsDrawn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'toggleFPSIsDisplayed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'toggleTextIsEnabled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'toggleCameraIsEdited'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setBackgroundColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>,
        // method 'setForegroundColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>,
        // method 'setSceneRadius'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setSceneCenter'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const qglviewer::Vec &, std::false_type>,
        // method 'setSceneBoundingBox'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const qglviewer::Vec &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const qglviewer::Vec &, std::false_type>,
        // method 'showEntireScene'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setCamera'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::Camera * const, std::false_type>,
        // method 'setManipulatedFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::ManipulatedFrame *, std::false_type>,
        // method 'setMouseGrabber'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::MouseGrabber *, std::false_type>,
        // method 'setFullScreen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setFullScreen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'toggleFullScreen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'toggleCameraMode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'copyBufferToTexture'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<GLint, std::false_type>,
        QtPrivate::TypeAndForceComplete<GLenum, std::false_type>,
        // method 'copyBufferToTexture'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<GLint, std::false_type>,
        // method 'setAnimationPeriod'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'startAnimation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stopAnimation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'animate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'toggleAnimation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'help'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'aboutQGLViewer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'select'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QMouseEvent *, std::false_type>,
        // method 'select'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>,
        // method 'setSelectBufferSize'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setSelectRegionWidth'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setSelectRegionHeight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setSelectedName'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setShortcut'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::KeyboardAction, std::false_type>,
        QtPrivate::TypeAndForceComplete<QKeyCombination, std::false_type>,
        // method 'setShortcut'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::KeyboardAction, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::Modifier, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::Key, std::false_type>,
        // method 'setKeyDescription'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QKeyCombination, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'setKeyDescription'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::KeyboardModifier, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::Key, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'setKeyDescription'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::Modifier, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::Key, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'clearShortcuts'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setPathKey'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<unsigned int, std::false_type>,
        // method 'setPathKey'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setPlayPathKeyboardModifiers'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::KeyboardModifiers, std::false_type>,
        // method 'setAddKeyFrameKeyboardModifiers'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::KeyboardModifiers, std::false_type>,
        // method 'setMouseBinding'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::KeyboardModifiers, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::MouseButton, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::MouseHandler, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::MouseAction, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setMouseBinding'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::KeyboardModifiers, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::MouseButton, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::MouseHandler, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::MouseAction, std::false_type>,
        // method 'setMouseBinding'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::KeyboardModifiers, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::MouseButton, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::ClickAction, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::MouseButtons, std::false_type>,
        // method 'setMouseBinding'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::KeyboardModifiers, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::MouseButton, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::ClickAction, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setMouseBinding'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::KeyboardModifiers, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::MouseButton, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::ClickAction, std::false_type>,
        // method 'setWheelBinding'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::KeyboardModifiers, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::MouseHandler, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::MouseAction, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setWheelBinding'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::KeyboardModifiers, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::MouseHandler, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::MouseAction, std::false_type>,
        // method 'setMouseBindingDescription'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::KeyboardModifiers, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::MouseButton, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::MouseButtons, std::false_type>,
        // method 'setMouseBindingDescription'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::KeyboardModifiers, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::MouseButton, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setMouseBindingDescription'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::KeyboardModifiers, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::MouseButton, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'setMouseBinding'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::Key, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::KeyboardModifiers, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::MouseButton, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::MouseHandler, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::MouseAction, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setMouseBinding'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::Key, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::KeyboardModifiers, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::MouseButton, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::MouseHandler, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::MouseAction, std::false_type>,
        // method 'setMouseBinding'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::Key, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::KeyboardModifiers, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::MouseButton, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::ClickAction, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::MouseButtons, std::false_type>,
        // method 'setMouseBinding'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::Key, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::KeyboardModifiers, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::MouseButton, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::ClickAction, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setMouseBinding'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::Key, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::KeyboardModifiers, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::MouseButton, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::ClickAction, std::false_type>,
        // method 'setWheelBinding'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::Key, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::KeyboardModifiers, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::MouseHandler, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::MouseAction, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setWheelBinding'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::Key, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::KeyboardModifiers, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::MouseHandler, std::false_type>,
        QtPrivate::TypeAndForceComplete<qglviewer::MouseAction, std::false_type>,
        // method 'setMouseBindingDescription'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::Key, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::KeyboardModifiers, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::MouseButton, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::MouseButtons, std::false_type>,
        // method 'setMouseBindingDescription'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::Key, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::KeyboardModifiers, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::MouseButton, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setMouseBindingDescription'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::Key, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::KeyboardModifiers, std::false_type>,
        QtPrivate::TypeAndForceComplete<::Qt::MouseButton, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'clearMouseBindings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resetVisualHints'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'delayedFullScreen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'hideMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void CGAL::QGLViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QGLViewer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->viewerInitialized(); break;
        case 1: _t->drawNeeded(); break;
        case 2: _t->drawFinished((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->animateNeeded(); break;
        case 4: _t->helpRequired(); break;
        case 5: _t->axisIsDrawnChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->gridIsDrawnChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->FPSIsDisplayedChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->textIsEnabledChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->cameraIsEditedChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 10: _t->pointSelected((*reinterpret_cast< std::add_pointer_t<const QMouseEvent*>>(_a[1]))); break;
        case 11: _t->mouseGrabberChanged((*reinterpret_cast< std::add_pointer_t<qglviewer::MouseGrabber*>>(_a[1]))); break;
        case 12: _t->contextIsDestroyed(); break;
        case 13: _t->needNewContext(); break;
        case 14: _t->setAxisIsDrawn((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 15: _t->setAxisIsDrawn(); break;
        case 16: _t->setGridIsDrawn((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 17: _t->setGridIsDrawn(); break;
        case 18: _t->setFPSIsDisplayed((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 19: _t->setFPSIsDisplayed(); break;
        case 20: _t->setTextIsEnabled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 21: _t->setTextIsEnabled(); break;
        case 22: _t->setCameraIsEdited((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 23: _t->setCameraIsEdited(); break;
        case 24: _t->toggleAxisIsDrawn(); break;
        case 25: _t->toggleGridIsDrawn(); break;
        case 26: _t->toggleFPSIsDisplayed(); break;
        case 27: _t->toggleTextIsEnabled(); break;
        case 28: _t->toggleCameraIsEdited(); break;
        case 29: _t->setBackgroundColor((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 30: _t->setForegroundColor((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 31: _t->setSceneRadius((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 32: _t->setSceneCenter((*reinterpret_cast< std::add_pointer_t<qglviewer::Vec>>(_a[1]))); break;
        case 33: _t->setSceneBoundingBox((*reinterpret_cast< std::add_pointer_t<qglviewer::Vec>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qglviewer::Vec>>(_a[2]))); break;
        case 34: _t->showEntireScene(); break;
        case 35: _t->setCamera((*reinterpret_cast< std::add_pointer_t<qglviewer::Camera*>>(_a[1]))); break;
        case 36: _t->setManipulatedFrame((*reinterpret_cast< std::add_pointer_t<qglviewer::ManipulatedFrame*>>(_a[1]))); break;
        case 37: _t->setMouseGrabber((*reinterpret_cast< std::add_pointer_t<qglviewer::MouseGrabber*>>(_a[1]))); break;
        case 38: _t->setFullScreen((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 39: _t->setFullScreen(); break;
        case 40: _t->toggleFullScreen(); break;
        case 41: _t->toggleCameraMode(); break;
        case 42: _t->copyBufferToTexture((*reinterpret_cast< std::add_pointer_t<GLint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<GLenum>>(_a[2]))); break;
        case 43: _t->copyBufferToTexture((*reinterpret_cast< std::add_pointer_t<GLint>>(_a[1]))); break;
        case 44: _t->setAnimationPeriod((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 45: _t->startAnimation(); break;
        case 46: _t->stopAnimation(); break;
        case 47: _t->animate(); break;
        case 48: _t->toggleAnimation(); break;
        case 49: _t->help(); break;
        case 50: _t->aboutQGLViewer(); break;
        case 51: _t->select((*reinterpret_cast< std::add_pointer_t<const QMouseEvent*>>(_a[1]))); break;
        case 52: _t->select((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 53: _t->setSelectBufferSize((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 54: _t->setSelectRegionWidth((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 55: _t->setSelectRegionHeight((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 56: _t->setSelectedName((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 57: _t->setShortcut((*reinterpret_cast< std::add_pointer_t<qglviewer::KeyboardAction>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QKeyCombination>>(_a[2]))); break;
        case 58: _t->setShortcut((*reinterpret_cast< std::add_pointer_t<qglviewer::KeyboardAction>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<::Qt::Modifier>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<::Qt::Key>>(_a[3]))); break;
        case 59: _t->setKeyDescription((*reinterpret_cast< std::add_pointer_t<QKeyCombination>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 60: _t->setKeyDescription((*reinterpret_cast< std::add_pointer_t<::Qt::KeyboardModifier>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<::Qt::Key>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 61: _t->setKeyDescription((*reinterpret_cast< std::add_pointer_t<::Qt::Modifier>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<::Qt::Key>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 62: _t->clearShortcuts(); break;
        case 63: _t->setPathKey((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2]))); break;
        case 64: _t->setPathKey((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 65: _t->setPlayPathKeyboardModifiers((*reinterpret_cast< std::add_pointer_t<::Qt::KeyboardModifiers>>(_a[1]))); break;
        case 66: _t->setAddKeyFrameKeyboardModifiers((*reinterpret_cast< std::add_pointer_t<::Qt::KeyboardModifiers>>(_a[1]))); break;
        case 67: _t->setMouseBinding((*reinterpret_cast< std::add_pointer_t<::Qt::KeyboardModifiers>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<::Qt::MouseButton>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qglviewer::MouseHandler>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<qglviewer::MouseAction>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[5]))); break;
        case 68: _t->setMouseBinding((*reinterpret_cast< std::add_pointer_t<::Qt::KeyboardModifiers>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<::Qt::MouseButton>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qglviewer::MouseHandler>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<qglviewer::MouseAction>>(_a[4]))); break;
        case 69: _t->setMouseBinding((*reinterpret_cast< std::add_pointer_t<::Qt::KeyboardModifiers>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<::Qt::MouseButton>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qglviewer::ClickAction>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<::Qt::MouseButtons>>(_a[5]))); break;
        case 70: _t->setMouseBinding((*reinterpret_cast< std::add_pointer_t<::Qt::KeyboardModifiers>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<::Qt::MouseButton>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qglviewer::ClickAction>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4]))); break;
        case 71: _t->setMouseBinding((*reinterpret_cast< std::add_pointer_t<::Qt::KeyboardModifiers>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<::Qt::MouseButton>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qglviewer::ClickAction>>(_a[3]))); break;
        case 72: _t->setWheelBinding((*reinterpret_cast< std::add_pointer_t<::Qt::KeyboardModifiers>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qglviewer::MouseHandler>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qglviewer::MouseAction>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4]))); break;
        case 73: _t->setWheelBinding((*reinterpret_cast< std::add_pointer_t<::Qt::KeyboardModifiers>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qglviewer::MouseHandler>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qglviewer::MouseAction>>(_a[3]))); break;
        case 74: _t->setMouseBindingDescription((*reinterpret_cast< std::add_pointer_t<::Qt::KeyboardModifiers>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<::Qt::MouseButton>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<::Qt::MouseButtons>>(_a[5]))); break;
        case 75: _t->setMouseBindingDescription((*reinterpret_cast< std::add_pointer_t<::Qt::KeyboardModifiers>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<::Qt::MouseButton>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4]))); break;
        case 76: _t->setMouseBindingDescription((*reinterpret_cast< std::add_pointer_t<::Qt::KeyboardModifiers>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<::Qt::MouseButton>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 77: _t->setMouseBinding((*reinterpret_cast< std::add_pointer_t<::Qt::Key>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<::Qt::KeyboardModifiers>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<::Qt::MouseButton>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<qglviewer::MouseHandler>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<qglviewer::MouseAction>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[6]))); break;
        case 78: _t->setMouseBinding((*reinterpret_cast< std::add_pointer_t<::Qt::Key>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<::Qt::KeyboardModifiers>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<::Qt::MouseButton>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<qglviewer::MouseHandler>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<qglviewer::MouseAction>>(_a[5]))); break;
        case 79: _t->setMouseBinding((*reinterpret_cast< std::add_pointer_t<::Qt::Key>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<::Qt::KeyboardModifiers>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<::Qt::MouseButton>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<qglviewer::ClickAction>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<::Qt::MouseButtons>>(_a[6]))); break;
        case 80: _t->setMouseBinding((*reinterpret_cast< std::add_pointer_t<::Qt::Key>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<::Qt::KeyboardModifiers>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<::Qt::MouseButton>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<qglviewer::ClickAction>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[5]))); break;
        case 81: _t->setMouseBinding((*reinterpret_cast< std::add_pointer_t<::Qt::Key>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<::Qt::KeyboardModifiers>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<::Qt::MouseButton>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<qglviewer::ClickAction>>(_a[4]))); break;
        case 82: _t->setWheelBinding((*reinterpret_cast< std::add_pointer_t<::Qt::Key>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<::Qt::KeyboardModifiers>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qglviewer::MouseHandler>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<qglviewer::MouseAction>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[5]))); break;
        case 83: _t->setWheelBinding((*reinterpret_cast< std::add_pointer_t<::Qt::Key>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<::Qt::KeyboardModifiers>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qglviewer::MouseHandler>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<qglviewer::MouseAction>>(_a[4]))); break;
        case 84: _t->setMouseBindingDescription((*reinterpret_cast< std::add_pointer_t<::Qt::Key>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<::Qt::KeyboardModifiers>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<::Qt::MouseButton>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<::Qt::MouseButtons>>(_a[6]))); break;
        case 85: _t->setMouseBindingDescription((*reinterpret_cast< std::add_pointer_t<::Qt::Key>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<::Qt::KeyboardModifiers>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<::Qt::MouseButton>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[5]))); break;
        case 86: _t->setMouseBindingDescription((*reinterpret_cast< std::add_pointer_t<::Qt::Key>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<::Qt::KeyboardModifiers>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<::Qt::MouseButton>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 87: _t->clearMouseBindings(); break;
        case 88: _t->resetVisualHints(); break;
        case 89: _t->delayedFullScreen(); break;
        case 90: _t->hideMessage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QGLViewer::*)();
            if (_t _q_method = &QGLViewer::viewerInitialized; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QGLViewer::*)();
            if (_t _q_method = &QGLViewer::drawNeeded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QGLViewer::*)(bool );
            if (_t _q_method = &QGLViewer::drawFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QGLViewer::*)();
            if (_t _q_method = &QGLViewer::animateNeeded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (QGLViewer::*)();
            if (_t _q_method = &QGLViewer::helpRequired; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (QGLViewer::*)(bool );
            if (_t _q_method = &QGLViewer::axisIsDrawnChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (QGLViewer::*)(bool );
            if (_t _q_method = &QGLViewer::gridIsDrawnChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (QGLViewer::*)(bool );
            if (_t _q_method = &QGLViewer::FPSIsDisplayedChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (QGLViewer::*)(bool );
            if (_t _q_method = &QGLViewer::textIsEnabledChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (QGLViewer::*)(bool );
            if (_t _q_method = &QGLViewer::cameraIsEditedChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (QGLViewer::*)(const QMouseEvent * );
            if (_t _q_method = &QGLViewer::pointSelected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (QGLViewer::*)(qglviewer::MouseGrabber * );
            if (_t _q_method = &QGLViewer::mouseGrabberChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (QGLViewer::*)();
            if (_t _q_method = &QGLViewer::contextIsDestroyed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (QGLViewer::*)();
            if (_t _q_method = &QGLViewer::needNewContext; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
    }
}

const QMetaObject *CGAL::QGLViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGAL::QGLViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCGALSCOPEQGLViewerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QOpenGLFunctions"))
        return static_cast< QOpenGLFunctions*>(this);
    return QOpenGLWidget::qt_metacast(_clname);
}

int CGAL::QGLViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 91)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 91;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 91)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 91;
    }
    return _id;
}

// SIGNAL 0
void CGAL::QGLViewer::viewerInitialized()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CGAL::QGLViewer::drawNeeded()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CGAL::QGLViewer::drawFinished(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CGAL::QGLViewer::animateNeeded()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void CGAL::QGLViewer::helpRequired()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void CGAL::QGLViewer::axisIsDrawnChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CGAL::QGLViewer::gridIsDrawnChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void CGAL::QGLViewer::FPSIsDisplayedChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void CGAL::QGLViewer::textIsEnabledChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void CGAL::QGLViewer::cameraIsEditedChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void CGAL::QGLViewer::pointSelected(const QMouseEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void CGAL::QGLViewer::mouseGrabberChanged(qglviewer::MouseGrabber * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void CGAL::QGLViewer::contextIsDestroyed()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void CGAL::QGLViewer::needNewContext()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}
QT_WARNING_POP
