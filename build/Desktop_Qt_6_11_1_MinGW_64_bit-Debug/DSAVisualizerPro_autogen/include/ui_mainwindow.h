/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QFrame *sideFrame;
    QLabel *lblAppTitle;
    QPushButton *btnSearching;
    QPushButton *btnGraph;
    QPushButton *btnSorting;
    QPushButton *btnAVL;
    QPushButton *btnBST;
    QPushButton *btnComplexity;
    QFrame *contentFrame;
    QVBoxLayout *verticalLayout_4;
    QLabel *titleLabel;
    QComboBox *cmbAlgorithm;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label;
    QSpinBox *targetSpinBox;
    QHBoxLayout *horizontalLayout_20;
    QPushButton *btnGenerate;
    QPushButton *btnStart;
    QPushButton *btnPause;
    QPushButton *btnReset;
    QHBoxLayout *horizontalLayout_21;
    QLabel *lblSpeed;
    QSlider *speedSlider;
    QLabel *lblVisualizationArea;
    QGraphicsView *graphicsView;
    QFrame *statsFrame;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lblComplexity;
    QLabel *lblComparisons;
    QLabel *lblSearchComparisons;
    QLabel *lblFoundIndex;
    QLabel *lblSwaps;
    QLabel *lblExecutionTime;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 854);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        sideFrame = new QFrame(centralwidget);
        sideFrame->setObjectName("sideFrame");
        sideFrame->setMinimumSize(QSize(220, 0));
        sideFrame->setMaximumSize(QSize(220, 16777215));
        sideFrame->setFrameShape(QFrame::Shape::StyledPanel);
        sideFrame->setFrameShadow(QFrame::Shadow::Raised);
        lblAppTitle = new QLabel(sideFrame);
        lblAppTitle->setObjectName("lblAppTitle");
        lblAppTitle->setGeometry(QRect(40, 10, 151, 21));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        lblAppTitle->setFont(font);
        btnSearching = new QPushButton(sideFrame);
        btnSearching->setObjectName("btnSearching");
        btnSearching->setGeometry(QRect(60, 190, 80, 24));
        btnGraph = new QPushButton(sideFrame);
        btnGraph->setObjectName("btnGraph");
        btnGraph->setGeometry(QRect(60, 310, 80, 24));
        btnSorting = new QPushButton(sideFrame);
        btnSorting->setObjectName("btnSorting");
        btnSorting->setGeometry(QRect(60, 150, 80, 24));
        btnAVL = new QPushButton(sideFrame);
        btnAVL->setObjectName("btnAVL");
        btnAVL->setGeometry(QRect(60, 270, 80, 24));
        btnBST = new QPushButton(sideFrame);
        btnBST->setObjectName("btnBST");
        btnBST->setGeometry(QRect(60, 230, 80, 24));
        btnComplexity = new QPushButton(sideFrame);
        btnComplexity->setObjectName("btnComplexity");
        btnComplexity->setGeometry(QRect(60, 350, 80, 24));

        horizontalLayout_4->addWidget(sideFrame);

        contentFrame = new QFrame(centralwidget);
        contentFrame->setObjectName("contentFrame");
        contentFrame->setMinimumSize(QSize(0, 0));
        contentFrame->setFrameShape(QFrame::Shape::StyledPanel);
        contentFrame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_4 = new QVBoxLayout(contentFrame);
        verticalLayout_4->setObjectName("verticalLayout_4");
        titleLabel = new QLabel(contentFrame);
        titleLabel->setObjectName("titleLabel");
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        titleLabel->setFont(font1);

        verticalLayout_4->addWidget(titleLabel);

        cmbAlgorithm = new QComboBox(contentFrame);
        cmbAlgorithm->addItem(QString());
        cmbAlgorithm->addItem(QString());
        cmbAlgorithm->addItem(QString());
        cmbAlgorithm->addItem(QString());
        cmbAlgorithm->addItem(QString());
        cmbAlgorithm->addItem(QString());
        cmbAlgorithm->addItem(QString());
        cmbAlgorithm->addItem(QString());
        cmbAlgorithm->addItem(QString());
        cmbAlgorithm->addItem(QString());
        cmbAlgorithm->addItem(QString());
        cmbAlgorithm->addItem(QString());
        cmbAlgorithm->addItem(QString());
        cmbAlgorithm->addItem(QString());
        cmbAlgorithm->addItem(QString());
        cmbAlgorithm->addItem(QString());
        cmbAlgorithm->addItem(QString());
        cmbAlgorithm->addItem(QString());
        cmbAlgorithm->setObjectName("cmbAlgorithm");

        verticalLayout_4->addWidget(cmbAlgorithm);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName("horizontalLayout_22");
        label = new QLabel(contentFrame);
        label->setObjectName("label");

        horizontalLayout_22->addWidget(label);

        targetSpinBox = new QSpinBox(contentFrame);
        targetSpinBox->setObjectName("targetSpinBox");
        targetSpinBox->setMaximum(500);

        horizontalLayout_22->addWidget(targetSpinBox);


        verticalLayout_4->addLayout(horizontalLayout_22);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        btnGenerate = new QPushButton(contentFrame);
        btnGenerate->setObjectName("btnGenerate");

        horizontalLayout_20->addWidget(btnGenerate);

        btnStart = new QPushButton(contentFrame);
        btnStart->setObjectName("btnStart");

        horizontalLayout_20->addWidget(btnStart);

        btnPause = new QPushButton(contentFrame);
        btnPause->setObjectName("btnPause");

        horizontalLayout_20->addWidget(btnPause);

        btnReset = new QPushButton(contentFrame);
        btnReset->setObjectName("btnReset");

        horizontalLayout_20->addWidget(btnReset);


        verticalLayout_4->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName("horizontalLayout_21");
        lblSpeed = new QLabel(contentFrame);
        lblSpeed->setObjectName("lblSpeed");

        horizontalLayout_21->addWidget(lblSpeed);

        speedSlider = new QSlider(contentFrame);
        speedSlider->setObjectName("speedSlider");
        speedSlider->setMinimum(1);
        speedSlider->setMaximum(100);
        speedSlider->setValue(50);
        speedSlider->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_21->addWidget(speedSlider);


        verticalLayout_4->addLayout(horizontalLayout_21);

        lblVisualizationArea = new QLabel(contentFrame);
        lblVisualizationArea->setObjectName("lblVisualizationArea");
        QFont font2;
        font2.setPointSize(17);
        font2.setBold(true);
        lblVisualizationArea->setFont(font2);

        verticalLayout_4->addWidget(lblVisualizationArea);

        graphicsView = new QGraphicsView(contentFrame);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setMinimumSize(QSize(0, 500));

        verticalLayout_4->addWidget(graphicsView);


        horizontalLayout_4->addWidget(contentFrame);


        verticalLayout->addLayout(horizontalLayout_4);

        statsFrame = new QFrame(centralwidget);
        statsFrame->setObjectName("statsFrame");
        statsFrame->setMinimumSize(QSize(0, 100));
        statsFrame->setFrameShape(QFrame::Shape::StyledPanel);
        statsFrame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayoutWidget_2 = new QWidget(statsFrame);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(-1, -1, 781, 101));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        lblComplexity = new QLabel(horizontalLayoutWidget_2);
        lblComplexity->setObjectName("lblComplexity");

        horizontalLayout_7->addWidget(lblComplexity);

        lblComparisons = new QLabel(horizontalLayoutWidget_2);
        lblComparisons->setObjectName("lblComparisons");

        horizontalLayout_7->addWidget(lblComparisons);

        lblSearchComparisons = new QLabel(horizontalLayoutWidget_2);
        lblSearchComparisons->setObjectName("lblSearchComparisons");

        horizontalLayout_7->addWidget(lblSearchComparisons);

        lblFoundIndex = new QLabel(horizontalLayoutWidget_2);
        lblFoundIndex->setObjectName("lblFoundIndex");

        horizontalLayout_7->addWidget(lblFoundIndex);

        lblSwaps = new QLabel(horizontalLayoutWidget_2);
        lblSwaps->setObjectName("lblSwaps");

        horizontalLayout_7->addWidget(lblSwaps);

        lblExecutionTime = new QLabel(horizontalLayoutWidget_2);
        lblExecutionTime->setObjectName("lblExecutionTime");

        horizontalLayout_7->addWidget(lblExecutionTime);


        verticalLayout->addWidget(statsFrame);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lblAppTitle->setText(QCoreApplication::translate("MainWindow", "DSA Visualizer", nullptr));
        btnSearching->setText(QCoreApplication::translate("MainWindow", "Searching", nullptr));
        btnGraph->setText(QCoreApplication::translate("MainWindow", "Graph", nullptr));
        btnSorting->setText(QCoreApplication::translate("MainWindow", "Sorting", nullptr));
        btnAVL->setText(QCoreApplication::translate("MainWindow", "AVL Tree", nullptr));
        btnBST->setText(QCoreApplication::translate("MainWindow", "BST", nullptr));
        btnComplexity->setText(QCoreApplication::translate("MainWindow", "Complexity", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "Welcome to DSA Visualizer Pro", nullptr));
        cmbAlgorithm->setItemText(0, QCoreApplication::translate("MainWindow", "Bubble Sort", nullptr));
        cmbAlgorithm->setItemText(1, QCoreApplication::translate("MainWindow", "Selection Sort", nullptr));
        cmbAlgorithm->setItemText(2, QCoreApplication::translate("MainWindow", "Insertion Sort", nullptr));
        cmbAlgorithm->setItemText(3, QCoreApplication::translate("MainWindow", "Merge Sort", nullptr));
        cmbAlgorithm->setItemText(4, QCoreApplication::translate("MainWindow", "Quick Sort", nullptr));
        cmbAlgorithm->setItemText(5, QCoreApplication::translate("MainWindow", "Heap Sort", nullptr));
        cmbAlgorithm->setItemText(6, QCoreApplication::translate("MainWindow", "Linear Search", nullptr));
        cmbAlgorithm->setItemText(7, QCoreApplication::translate("MainWindow", "Binary Search", nullptr));
        cmbAlgorithm->setItemText(8, QCoreApplication::translate("MainWindow", "DFS", nullptr));
        cmbAlgorithm->setItemText(9, QCoreApplication::translate("MainWindow", "BFS", nullptr));
        cmbAlgorithm->setItemText(10, QCoreApplication::translate("MainWindow", "Preorder Traversal", nullptr));
        cmbAlgorithm->setItemText(11, QCoreApplication::translate("MainWindow", "Inorder Traversal", nullptr));
        cmbAlgorithm->setItemText(12, QCoreApplication::translate("MainWindow", "Postorder Traversal", nullptr));
        cmbAlgorithm->setItemText(13, QCoreApplication::translate("MainWindow", "Level Order Traversal", nullptr));
        cmbAlgorithm->setItemText(14, QCoreApplication::translate("MainWindow", "Dijkstra", nullptr));
        cmbAlgorithm->setItemText(15, QCoreApplication::translate("MainWindow", "Prim MST", nullptr));
        cmbAlgorithm->setItemText(16, QCoreApplication::translate("MainWindow", "Kruskal MST", nullptr));
        cmbAlgorithm->setItemText(17, QCoreApplication::translate("MainWindow", "Topological Sort", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "Target:", nullptr));
        btnGenerate->setText(QCoreApplication::translate("MainWindow", "Generate", nullptr));
        btnStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        btnPause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        btnReset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        lblSpeed->setText(QCoreApplication::translate("MainWindow", "Speed: ", nullptr));
        lblVisualizationArea->setText(QCoreApplication::translate("MainWindow", "Visualization Area", nullptr));
        lblComplexity->setText(QCoreApplication::translate("MainWindow", "Complexity: -", nullptr));
        lblComparisons->setText(QCoreApplication::translate("MainWindow", "Comparisons: 0", nullptr));
        lblSearchComparisons->setText(QCoreApplication::translate("MainWindow", "Search Comparisons: ", nullptr));
        lblFoundIndex->setText(QCoreApplication::translate("MainWindow", "Found Index: ", nullptr));
        lblSwaps->setText(QCoreApplication::translate("MainWindow", "Swaps: 0", nullptr));
        lblExecutionTime->setText(QCoreApplication::translate("MainWindow", "Execution Time: 0 ms", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
