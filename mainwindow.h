#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <vector>
#include <QElapsedTimer>
#include <utility>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <stack>
#include <queue>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_btnGenerate_clicked();
    void on_btnStart_clicked();
    void on_btnPause_clicked();
    void on_btnReset_clicked();
    void on_speedSlider_valueChanged(int value);

    void bubbleSortStep();
    void selectionSortStep();
    void insertionSortStep();
    void mergeSortStep();
    void quickSortStep();
    void heapSortStep();

    void linearSearchStep();
    void binarySearchStep();

    void dfsStep();
    void bfsStep();

    void preorderStep();
    void inorderStep();
    void postorderStep();
    void levelOrderStep();

    void dijkstraStep();
    void primStep();
    void kruskalStep();
    void topologicalSortStep();

    void generateQuickSortOperations(
        std::vector<int>& tempArr,
        int low,
        int high);

    int partitionOperations(
        std::vector<int>& tempArr,
        int low,
        int high);

    void generateMergeSortOperations(
        std::vector<int>& tempArr,
        int left,
        int right);

    void mergeOperationHelper(
        std::vector<int>& tempArr,
        int left,
        int mid,
        int right);

    void generateHeapOperations(std::vector<int>& tempArr);
    void heapifyOperations(std::vector<int>& tempArr,int n,int i);

    void startSelectedAlgorithm();
    void generateRandomBars();
    void drawBars();

private:

    static constexpr int ARRAY_SIZE = 25;
    static constexpr int MIN_BAR_HEIGHT = 50;
    static constexpr int MAX_BAR_HEIGHT = 350;

    int findSet(int v);
    void unionSet(int a,int b);

    std::vector<int> parent;
    QElapsedTimer elapsedTimer;

    int selectionOuter;
    int selectionInner;
    int selectionMinIndex;

    int insertionOuter;
    int insertionInner;

    int targetValue;
    int foundIndex;
    int searchIndex;

    int binaryLeft;
    int binaryRight;
    int binaryMid;

    std::vector<std::pair<int,int>> quickOperations;
    int quickOperationIndex;

    std::vector<std::pair<int,int>> mergeOperations;
    int mergeOperationIndex;

    std::vector<std::pair<int,int>> heapOperations;
    int heapOperationIndex;

    int compareIndex1;
    int compareIndex2;

    int swapIndex1;
    int swapIndex2;

    bool sortingFinished;

    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    QTimer *sortTimer;

    std::vector<int> originalArray;

    std::vector<int> arr;

    // DFS
    void createGraph();
    void drawGraph();

    std::vector<std::vector<int>> graph;

    std::vector<bool> visitedDFS;

    std::stack<int> dfsStack;

    std::vector<QPointF> nodePositions;

    int currentDFSNode;

    std::queue<int> bfsQueue;

    std::vector<bool> visitedBFS;

    int currentBFSNode;

    int comparisons;
    int swaps;

    // Tree Traversal

    struct TreeNode
    {
        int value;

        TreeNode* left;
        TreeNode* right;
    };

    TreeNode* root;

    std::vector<int> traversalOrder;

    int traversalIndex;

    int currentTreeNode;

    void createTree();
    void deleteTree(TreeNode* node)
    {
        if(!node) return;

        deleteTree(node->left);
        deleteTree(node->right);

        delete node;
    }
    void preorderTraversal(
        TreeNode* node);

    void inorderTraversal(
        TreeNode* node);

    void postorderTraversal(
        TreeNode* node);

    void levelOrderTraversal(
        TreeNode* node);

    void drawTree();

    // Dijkstra

    std::vector<int> distances;
    std::vector<bool> visitedDijkstra;
    int currentDijkstraNode;

    // Prim

    std::vector<std::pair<int,int>> primEdges;
    std::vector<bool> visitedPrim;
    int currentPrimNode;

    // Kruskal

    std::vector<std::pair<int,int>> mstEdges;
    int kruskalEdgeIndex;

    // Topological

    std::vector<int> topoOrder;
    int topoIndex;
    int currentTopoNode;

    int i;
    int j;

};

#endif