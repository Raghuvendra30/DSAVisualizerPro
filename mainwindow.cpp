#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRandomGenerator>
#include <QBrush>
#include <QPen>
#include <algorithm>
#include <climits>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    sortTimer = new QTimer(this);

    selectionOuter = 0;
    selectionInner = 1;
    selectionMinIndex = 0;

    insertionOuter = 1;
    insertionInner = 1;

    mergeOperationIndex = 0;
    quickOperationIndex = 0;
    heapOperationIndex = 0;

    currentDFSNode = -1;
    visitedDFS.clear();

    currentBFSNode = -1;
    visitedBFS.clear();

    root = nullptr;

    traversalIndex = 0;

    currentTreeNode = -1;

    while(!bfsQueue.empty())
    {
        bfsQueue.pop();
    }

    currentDijkstraNode = -1;

    distances.clear();

    visitedDijkstra.clear();

    currentPrimNode = -1;

    visitedPrim.clear();

    kruskalEdgeIndex = 0;

    mstEdges.clear();

    topoOrder.clear();

    topoIndex = 0;

    currentTopoNode = -1;

    targetValue = -1;

    searchIndex = 0;

    binaryLeft = 0;
    binaryRight = 0;
    binaryMid = 0;

    foundIndex = -1;

    compareIndex1 = -1;
    compareIndex2 = -1;

    swapIndex1 = -1;
    swapIndex2 = -1;

    sortingFinished = false;
    comparisons = 0;
    swaps = 0;

    i = 0;
    j = 0;

    connect(sortTimer,
            &QTimer::timeout,
            this,
            &MainWindow::bubbleSortStep);

    generateRandomBars();
}

MainWindow::~MainWindow()
{
    sortTimer->stop();

    if(root)
    {
        deleteTree(root);
        root = nullptr;
    }

    delete ui;
}

int MainWindow::findSet(int v)
{
    if(parent[v] == v)
        return v;

    return parent[v] = findSet(parent[v]);
}

void MainWindow::unionSet(int a,int b)
{
    a = findSet(a);
    b = findSet(b);

    if(a != b)
        parent[b] = a;
}

void MainWindow::generateRandomBars()
{
    arr.clear();

    for(int k = 0; k < ARRAY_SIZE; k++)
    {
        arr.push_back(
            QRandomGenerator::global()->bounded(MIN_BAR_HEIGHT, MAX_BAR_HEIGHT)
            );
    }

    originalArray = arr;

    drawBars();
}

void MainWindow::drawBars()
{
    scene->clear();

    int x = 0;

    for(size_t k = 0; k < arr.size(); k++)
    {
        QColor color = Qt::blue;

        if((int)k == foundIndex)
        {
            color = Qt::green;
        }
        else if(sortingFinished)
        {
            color = Qt::green;
        }
        else if((int)k == swapIndex1 ||
                (int)k == swapIndex2)
        {
            color = Qt::yellow;
        }
        else if((int)k == compareIndex1 ||
                (int)k == compareIndex2)
        {
            color = Qt::red;
        }

        scene->addRect(
            x,
            MAX_BAR_HEIGHT - arr[k],
            25,
            arr[k],
            QPen(Qt::black),
            QBrush(color)
            );

        x += 30;
    }
}

void MainWindow::bubbleSortStep()
{
    int n = static_cast<int>(arr.size());

    if(i >= n - 1)
    {
        sortTimer->stop();

        compareIndex1 = -1;
        compareIndex2 = -1;

        swapIndex1 = -1;
        swapIndex2 = -1;

        ui->lblExecutionTime->setText(
            "Completed in " +
            QString::number(elapsedTimer.elapsed()) +
            " ms");

        sortingFinished = true;

        drawBars();
        return;
    }
    compareIndex1 = j;
    compareIndex2 = j + 1;

    swapIndex1 = -1;
    swapIndex2 = -1;

    comparisons++;

    if(arr[j] > arr[j + 1])
    {
        std::swap(arr[j], arr[j + 1]);
        swaps++;
        swapIndex1 = j;
        swapIndex2 = j + 1;
    }

    ui->lblComparisons->setText(
        "Comparisons: " + QString::number(comparisons));

    ui->lblSwaps->setText(
        "Swaps: " + QString::number(swaps));

    ui->lblExecutionTime->setText(
        QString::number(elapsedTimer.elapsed()) + " ms");

    drawBars();

    j++;

    if(j >= n - i - 1)
    {
        j = 0;
        i++;
    }
}

// ------------------------------------
// Future Algorithms
// ------------------------------------

void MainWindow::selectionSortStep()
{
    int n = static_cast<int>(arr.size());

    if(selectionOuter >= n - 1)
    {
        sortTimer->stop();

        compareIndex1 = -1;
        compareIndex2 = -1;

        swapIndex1 = -1;
        swapIndex2 = -1;

        ui->lblExecutionTime->setText(
            "Completed in " +
            QString::number(elapsedTimer.elapsed()) +
            " ms");

        sortingFinished = true;

        drawBars();
        return;
    }

    if(selectionInner == selectionOuter + 1)
    {
        selectionMinIndex = selectionOuter;
    }

    if(selectionInner < n)
    {
        compareIndex1 = selectionInner;
        compareIndex2 = selectionMinIndex;

        comparisons++;

        if(arr[selectionInner] < arr[selectionMinIndex])
        {
            selectionMinIndex = selectionInner;
        }

        selectionInner++;
    }
    else
    {
        if(selectionOuter != selectionMinIndex)
        {
            std::swap(
                arr[selectionOuter],
                arr[selectionMinIndex]);

            swaps++;

            swapIndex1 = selectionOuter;
            swapIndex2 = selectionMinIndex;
        }

        selectionOuter++;
        selectionInner = selectionOuter + 1;
    }

    ui->lblComparisons->setText(
        "Comparisons: " + QString::number(comparisons));

    ui->lblSwaps->setText(
        "Swaps: " + QString::number(swaps));

    ui->lblExecutionTime->setText(
        QString::number(elapsedTimer.elapsed()) + " ms");

    drawBars();
}

void MainWindow::insertionSortStep()
{
    int n = static_cast<int>(arr.size());

    if(insertionOuter >= n)
    {
        sortTimer->stop();

        compareIndex1 = -1;
        compareIndex2 = -1;

        swapIndex1 = -1;
        swapIndex2 = -1;

        ui->lblExecutionTime->setText(
            "Completed in " +
            QString::number(elapsedTimer.elapsed()) +
            " ms");

        sortingFinished = true;

        drawBars();
        return;
    }

    if(insertionInner > 0 &&
        arr[insertionInner - 1] > arr[insertionInner])
    {
        compareIndex1 = insertionInner;
        compareIndex2 = insertionInner - 1;

        std::swap(
            arr[insertionInner],
            arr[insertionInner - 1]);

        swapIndex1 = insertionInner;
        swapIndex2 = insertionInner - 1;

        swaps++;
        comparisons++;

        insertionInner--;
    }
    else
    {
        insertionOuter++;
        insertionInner = insertionOuter;
    }

    ui->lblComparisons->setText(
        "Comparisons: " + QString::number(comparisons));

    ui->lblSwaps->setText(
        "Swaps: " + QString::number(swaps));

    ui->lblExecutionTime->setText(
        QString::number(elapsedTimer.elapsed()) + " ms");

    drawBars();
}

void MainWindow::mergeSortStep()
{
    if(mergeOperationIndex >=
        static_cast<int>(mergeOperations.size()))
    {
        sortTimer->stop();

        compareIndex1 = -1;
        compareIndex2 = -1;

        swapIndex1 = -1;
        swapIndex2 = -1;

        ui->lblExecutionTime->setText(
            "Completed in " +
            QString::number(
                elapsedTimer.elapsed()) +
            " ms");

        sortingFinished = true;
        drawBars();
        return;
    }

    auto operation =
        mergeOperations[
            mergeOperationIndex];

    int index = operation.first;
    int value = operation.second;

    arr[index] = value;

    swaps++;

    ui->lblSwaps->setText(
        "Swaps: " +
        QString::number(swaps));

    compareIndex1 = index;
    compareIndex2 = index;

    comparisons++;

    ui->lblComparisons->setText(
        "Comparisons: " +
        QString::number(comparisons));

    ui->lblExecutionTime->setText(
        QString::number(
            elapsedTimer.elapsed()) +
        " ms");

    swapIndex1 = -1;
    swapIndex2 = -1;

    drawBars();

    mergeOperationIndex++;
}

void MainWindow::quickSortStep()
{
    if(quickOperationIndex >=
        static_cast<int>(quickOperations.size()))
    {
        sortTimer->stop();

        compareIndex1 = -1;
        compareIndex2 = -1;

        swapIndex1 = -1;
        swapIndex2 = -1;

        ui->lblExecutionTime->setText(
            "Completed in " +
            QString::number(
                elapsedTimer.elapsed()) +
            " ms");

        sortingFinished = true;
        drawBars();
        return;
    }

    auto operation =
        quickOperations[
            quickOperationIndex];

    int a = operation.first;
    int b = operation.second;

    compareIndex1 = a;
    compareIndex2 = b;

    std::swap(
        arr[a],
        arr[b]);

    swapIndex1 = a;
    swapIndex2 = b;

    swaps++;
    comparisons++;

    ui->lblSwaps->setText(
        "Swaps: " +
        QString::number(swaps));

    ui->lblComparisons->setText(
        "Comparisons: " +
        QString::number(comparisons));

    ui->lblExecutionTime->setText(
        QString::number(
            elapsedTimer.elapsed()) +
        " ms");

    drawBars();

    quickOperationIndex++;
}

void MainWindow::heapSortStep()
{
    if(heapOperationIndex >=
        static_cast<int>(heapOperations.size()))
    {

        sortTimer->stop();

        compareIndex1 = -1;
        compareIndex2 = -1;

        swapIndex1 = -1;
        swapIndex2 = -1;

        ui->lblExecutionTime->setText(
            "Completed in " +
            QString::number(
                elapsedTimer.elapsed()) +
            " ms");

        sortingFinished = true;

        drawBars();
        return;
    }

    auto operation =
        heapOperations[
            heapOperationIndex];

    int a = operation.first;
    int b = operation.second;

    compareIndex1 = a;
    compareIndex2 = b;

    std::swap(
        arr[a],
        arr[b]);

    swapIndex1 = a;
    swapIndex2 = b;

    swaps++;
    comparisons++;

    ui->lblSwaps->setText(
        "Swaps: " +
        QString::number(swaps));

    ui->lblComparisons->setText(
        "Comparisons: " +
        QString::number(comparisons));

    ui->lblExecutionTime->setText(
        QString::number(
            elapsedTimer.elapsed()) +
        " ms");

    drawBars();

    heapOperationIndex++;
}

void MainWindow::startSelectedAlgorithm()
{
    QString algo =
        ui->cmbAlgorithm->currentText();

    disconnect(sortTimer, &QTimer::timeout, nullptr, nullptr);

    if(algo == "Bubble Sort")
    {
        connect(sortTimer,
                &QTimer::timeout,
                this,
                &MainWindow::bubbleSortStep);

        ui->lblComplexity->setText(
            "Complexity: O(n²)");
    }

    else if(algo == "Selection Sort")
    {
        connect(sortTimer,
                &QTimer::timeout,
                this,
                &MainWindow::selectionSortStep);

        ui->lblComplexity->setText(
            "Complexity: O(n²)");
    }

    else if(algo == "Insertion Sort")
    {
        connect(sortTimer,
                &QTimer::timeout,
                this,
                &MainWindow::insertionSortStep);

        ui->lblComplexity->setText(
            "Complexity: O(n²)");
    }

    else if(algo == "Merge Sort")
    {
        mergeOperations.clear();
        mergeOperationIndex = 0;

        std::vector<int> temp = arr;

        generateMergeSortOperations(
            temp,
            0,
            temp.size() - 1);

        connect(sortTimer,
                &QTimer::timeout,
                this,
                &MainWindow::mergeSortStep);

        ui->lblComplexity->setText(
            "Complexity: O(n log n)");
    }

    else if(algo == "Quick Sort")
    {
        quickOperations.clear();
        quickOperationIndex = 0;

        std::vector<int> temp = arr;

        generateQuickSortOperations(
            temp,
            0,
            temp.size()-1);

        connect(sortTimer,
                &QTimer::timeout,
                this,
                &MainWindow::quickSortStep);

        ui->lblComplexity->setText(
            "Complexity: O(n log n)");
    }

    else if(algo == "Heap Sort")
    {
        heapOperations.clear();
        heapOperationIndex = 0;

        std::vector<int> temp = arr;

        generateHeapOperations(temp);

        connect(sortTimer,
                &QTimer::timeout,
                this,
                &MainWindow::heapSortStep);

        ui->lblComplexity->setText(
            "Complexity: O(n log n)");
    }

    else if(algo == "Linear Search")
    {
        connect(sortTimer,
                &QTimer::timeout,
                this,
                &MainWindow::linearSearchStep);

        ui->lblComplexity->setText(
            "Complexity: O(n)");
    }

    else if(algo == "Binary Search")
    {
        arr = originalArray;

        std::sort(arr.begin(), arr.end());

        binaryLeft = 0;
        binaryRight =
            arr.empty() ? -1 :
            static_cast<int>(arr.size()) - 1;

        drawBars();

        connect(sortTimer,
                &QTimer::timeout,
                this,
                &MainWindow::binarySearchStep);

        ui->lblComplexity->setText(
            "Complexity: O(log n)");
    }

    else if(algo == "DFS")
    {
        createGraph();

        visitedDFS.assign(
            graph.size(),
            false
            );

        while(!dfsStack.empty())
            dfsStack.pop();

        dfsStack.push(0);

        currentDFSNode = -1;

        connect(
            sortTimer,
            &QTimer::timeout,
            this,
            &MainWindow::dfsStep
            );

        ui->lblComplexity->setText(
            "Complexity: O(V + E)"
            );

        drawGraph();
    }

    else if(algo == "BFS")
    {
        createGraph();

        visitedBFS.assign(
            graph.size(),
            false);

        while(!bfsQueue.empty())
        {
            bfsQueue.pop();
        }

        visitedBFS[0] = true;
        bfsQueue.push(0);

        currentBFSNode = -1;

        connect(
            sortTimer,
            &QTimer::timeout,
            this,
            &MainWindow::bfsStep
            );

        ui->lblComplexity->setText(
            "Complexity: O(V + E)"
            );

        drawGraph();
    }

    else if(algo == "Preorder Traversal")
    {
        createTree();

        traversalOrder.clear();

        preorderTraversal(root);

        traversalIndex = 0;

        connect(
            sortTimer,
            &QTimer::timeout,
            this,
            &MainWindow::preorderStep);

        ui->lblComplexity->setText(
            "Complexity: O(n)");

        drawTree();
    }

    else if(algo == "Inorder Traversal")
    {
        createTree();

        traversalOrder.clear();

        inorderTraversal(root);

        traversalIndex = 0;

        connect(
            sortTimer,
            &QTimer::timeout,
            this,
            &MainWindow::inorderStep);

        ui->lblComplexity->setText(
            "Complexity: O(n)");

        drawTree();
    }

    else if(algo == "Postorder Traversal")
    {
        createTree();

        traversalOrder.clear();

        postorderTraversal(root);

        traversalIndex = 0;

        connect(
            sortTimer,
            &QTimer::timeout,
            this,
            &MainWindow::postorderStep);

        ui->lblComplexity->setText(
            "Complexity: O(n)");

        drawTree();
    }

    else if(algo == "Level Order Traversal")
    {
        createTree();

        traversalOrder.clear();

        levelOrderTraversal(root);

        traversalIndex = 0;

        connect(
            sortTimer,
            &QTimer::timeout,
            this,
            &MainWindow::levelOrderStep);

        ui->lblComplexity->setText(
            "Complexity: O(n)");

        drawTree();
    }

    else if(algo == "Dijkstra")
    {
        createGraph();

        distances.assign(
            graph.size(),
            INT_MAX);

        visitedDijkstra.assign(
            graph.size(),
            false);

        distances[0] = 0;

        currentDijkstraNode = -1;

        connect(
            sortTimer,
            &QTimer::timeout,
            this,
            &MainWindow::dijkstraStep);

        ui->lblComplexity->setText(
            "Complexity: O(V²)");

        drawGraph();
    }

    else if(algo == "Prim MST")
    {
        createGraph();

        visitedPrim.assign(
            graph.size(),
            false);

        currentPrimNode = -1;

        connect(
            sortTimer,
            &QTimer::timeout,
            this,
            &MainWindow::primStep);

        ui->lblComplexity->setText(
            "Complexity: O(V²)");

        drawGraph();
    }

    else if(algo == "Kruskal MST")
    {

        createGraph();

        parent.resize(graph.size());

        for(int i = 0; i < static_cast<int>(graph.size()); i++)
        {
            parent[i] = i;
        }

        mstEdges.clear();

        kruskalEdgeIndex = 0;

        connect(
            sortTimer,
            &QTimer::timeout,
            this,
            &MainWindow::kruskalStep);

        ui->lblComplexity->setText(
            "Complexity: O(E log E)");

        drawGraph();
    }

    else if(algo == "Topological Sort")
    {
        graph.clear();

        graph.resize(6);

        graph[0] = {1,2};
        graph[1] = {3};
        graph[2] = {3,4};
        graph[3] = {5};
        graph[4] = {5};
        graph[5] = {};

        nodePositions.clear();

        nodePositions.push_back(QPointF(300,50));
        nodePositions.push_back(QPointF(180,150));
        nodePositions.push_back(QPointF(420,150));
        nodePositions.push_back(QPointF(180,280));
        nodePositions.push_back(QPointF(420,280));
        nodePositions.push_back(QPointF(300,380));

        topoOrder.clear();

        topoIndex = 0;

        currentTopoNode = -1;

        std::vector<int> indegree(
            graph.size(),
            0);

        for(int i = 0;
             i < static_cast<int>(graph.size());
             i++)
        {
            for(int neighbour : graph[i])
            {
                indegree[neighbour]++;
            }
        }

        std::queue<int> q;

        for(int i = 0;
             i < static_cast<int>(indegree.size());
             i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            topoOrder.push_back(node);

            for(int neighbour : graph[node])
            {
                indegree[neighbour]--;

                if(indegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }

        connect(
            sortTimer,
            &QTimer::timeout,
            this,
            &MainWindow::topologicalSortStep);

        ui->lblComplexity->setText(
            "Complexity: O(V + E)");

        drawGraph();
    }
}

void MainWindow::on_btnGenerate_clicked()
{
    sortTimer->stop();

    comparisons = 0;
    swaps = 0;

    ui->lblComparisons->setText("Comparisons: 0");
    ui->lblSwaps->setText("Swaps: 0");
    ui->lblExecutionTime->setText("Ready");
    ui->lblComplexity->setText("Complexity: -");
    ui->lblSearchComparisons->setText("Search Comparisons: 0");
    ui->lblFoundIndex->setText("Found Index: -");

    sortingFinished = false;

    compareIndex1 = -1;
    compareIndex2 = -1;

    swapIndex1 = -1;
    swapIndex2 = -1;
    selectionOuter = 0;
    selectionInner = 1;
    selectionMinIndex = 0;

    insertionOuter = 1;
    insertionInner = 1;

    mergeOperationIndex = 0;
    mergeOperations.clear();

    quickOperationIndex = 0;
    quickOperations.clear();

    heapOperationIndex = 0;
    heapOperations.clear();

    searchIndex = 0;

    binaryLeft = 0;
    binaryRight = 0;
    binaryMid = 0;
    foundIndex = -1;
    targetValue = -1;

    currentDFSNode = -1;

    visitedDFS.clear();

    while(!dfsStack.empty())
    {
        dfsStack.pop();
    }

    visitedBFS.clear();

    while(!bfsQueue.empty())
    {
        bfsQueue.pop();
    }

    currentBFSNode = -1;

    if(root != nullptr)
    {
        deleteTree(root);
        root = nullptr;
    }

    traversalOrder.clear();

    traversalIndex = 0;

    currentTreeNode = -1;

    currentDijkstraNode = -1;

    distances.clear();

    visitedDijkstra.clear();

    primEdges.clear();

    currentPrimNode = -1;

    visitedPrim.clear();

    mstEdges.clear();

    kruskalEdgeIndex = 0;

    topoOrder.clear();

    topoIndex = 0;

    currentTopoNode = -1;

    QString algo =
        ui->cmbAlgorithm->currentText();

    if(algo == "Topological Sort")
    {
        graph.clear();

        graph.resize(6);

        graph[0] = {1,2};
        graph[1] = {3};
        graph[2] = {3,4};
        graph[3] = {5};
        graph[4] = {5};
        graph[5] = {};

        nodePositions.clear();

        nodePositions.push_back(QPointF(300,50));
        nodePositions.push_back(QPointF(180,150));
        nodePositions.push_back(QPointF(420,150));
        nodePositions.push_back(QPointF(180,280));
        nodePositions.push_back(QPointF(420,280));
        nodePositions.push_back(QPointF(300,380));

        drawGraph();
    }
    else if(algo == "DFS" ||
             algo == "BFS" ||
             algo == "Dijkstra" ||
             algo == "Prim MST" ||
             algo == "Kruskal MST")
    {
        createGraph();
        drawGraph();
    }
    else if(algo.contains("Traversal"))
    {
        createTree();
        drawTree();
    }
    else
    {
        generateRandomBars();
    }
}
void MainWindow::on_btnStart_clicked()
{
    sortTimer->stop();
    targetValue =
        ui->targetSpinBox->value();
    foundIndex = -1;
    mergeOperationIndex = 0;
    quickOperationIndex = 0;
    heapOperationIndex = 0;

    arr = originalArray;

    elapsedTimer.start();
    sortingFinished = false;
    comparisons = 0;
    swaps = 0;

    visitedBFS.clear();

    while(!bfsQueue.empty())
    {
        bfsQueue.pop();
    }

    currentBFSNode = -1;

    visitedDFS.clear();

    while(!dfsStack.empty())
    {
        dfsStack.pop();
    }

    currentDFSNode = -1;

    traversalOrder.clear();

    traversalIndex = 0;

    currentTreeNode = -1;

    if(root != nullptr)
    {
        deleteTree(root);
        root = nullptr;
    }

    currentDijkstraNode = -1;

    distances.clear();

    visitedDijkstra.clear();

    primEdges.clear();

    currentPrimNode = -1;

    visitedPrim.clear();

    mstEdges.clear();

    kruskalEdgeIndex = 0;

    topoOrder.clear();

    topoIndex = 0;

    currentTopoNode = -1;

    startSelectedAlgorithm();

    compareIndex1 = -1;
    compareIndex2 = -1;

    swapIndex1 = -1;
    swapIndex2 = -1;

    if(ui->cmbAlgorithm->currentText() == "DFS" ||
        ui->cmbAlgorithm->currentText() == "BFS")
    {
        comparisons = 0;
    }

    selectionOuter = 0;
    selectionInner = 1;
    selectionMinIndex = 0;

    insertionOuter = 1;
    insertionInner = 1;

    searchIndex = 0;

    binaryLeft = 0;
    binaryRight =
    arr.empty() ? -1 :
    static_cast<int>(arr.size()) - 1;
    binaryMid = 0;
    foundIndex = -1;

    i = 0;
    j = 0;

    ui->lblComparisons->setText("Comparisons: 0");
    ui->lblSwaps->setText("Swaps: 0");
    ui->lblSearchComparisons->setText("Search Comparisons: 0");
    ui->lblFoundIndex->setText("Found Index: -");
    ui->lblExecutionTime->setText("Running...");

    sortTimer->start(
        101 - ui->speedSlider->value()
        );
}
void MainWindow::on_btnPause_clicked()
{
    if(sortTimer->isActive())
    {
        sortTimer->stop();

        ui->lblExecutionTime->setText("Paused");
    }
    else
    {
        sortTimer->start(
            101 - ui->speedSlider->value()
            );

        ui->lblExecutionTime->setText("Running...");
    }
}
void MainWindow::on_btnReset_clicked()
{
    sortTimer->stop();

    comparisons = 0;
    swaps = 0;

    i = 0;
    j = 0;

    ui->lblComplexity->setText("Complexity: -");
    ui->lblComparisons->setText("Comparisons: 0");
    ui->lblSearchComparisons->setText("Search Comparisons: 0");
    ui->lblFoundIndex->setText("Found Index: -");
    ui->lblSwaps->setText("Swaps: 0");
    ui->lblExecutionTime->setText("Reset");

    sortingFinished = false;

    compareIndex1 = -1;
    compareIndex2 = -1;

    swapIndex1 = -1;
    swapIndex2 = -1;
    selectionOuter = 0;
    selectionInner = 1;
    selectionMinIndex = 0;

    insertionOuter = 1;
    insertionInner = 1;

    mergeOperationIndex = 0;
    mergeOperations.clear();

    quickOperationIndex = 0;
    quickOperations.clear();

    heapOperationIndex = 0;
    heapOperations.clear();

    searchIndex = 0;

    binaryLeft = 0;
    binaryRight = 0;
    binaryMid = 0;
    foundIndex = -1;
    targetValue = -1;

    currentDFSNode = -1;

    visitedDFS.clear();

    while(!dfsStack.empty())
    {
        dfsStack.pop();
    }

    visitedBFS.clear();

    while(!bfsQueue.empty())
    {
        bfsQueue.pop();
    }

    currentBFSNode = -1;

    if(root != nullptr)
    {
        deleteTree(root);
        root = nullptr;
    }

    traversalOrder.clear();

    traversalIndex = 0;

    currentTreeNode = -1;

    currentDijkstraNode = -1;

    distances.clear();

    visitedDijkstra.clear();

    primEdges.clear();

    currentPrimNode = -1;

    visitedPrim.clear();

    mstEdges.clear();

    kruskalEdgeIndex = 0;

    topoOrder.clear();

    topoIndex = 0;

    currentTopoNode = -1;

    QString algo =
        ui->cmbAlgorithm->currentText();

    if(algo == "Topological Sort")
    {
        graph.clear();

        graph.resize(6);

        graph[0] = {1,2};
        graph[1] = {3};
        graph[2] = {3,4};
        graph[3] = {5};
        graph[4] = {5};
        graph[5] = {};

        nodePositions.clear();

        nodePositions.push_back(QPointF(300,50));
        nodePositions.push_back(QPointF(180,150));
        nodePositions.push_back(QPointF(420,150));
        nodePositions.push_back(QPointF(180,280));
        nodePositions.push_back(QPointF(420,280));
        nodePositions.push_back(QPointF(300,380));

        drawGraph();
    }
    else if(algo == "DFS" ||
             algo == "BFS" ||
             algo == "Dijkstra" ||
             algo == "Prim MST" ||
             algo == "Kruskal MST")
    {
        createGraph();
        drawGraph();
    }
    else if(algo.contains("Traversal"))
    {
        createTree();
        drawTree();
    }
    else
    {
        generateRandomBars();
    }
}
void MainWindow::on_speedSlider_valueChanged(int value)
{
    if(sortTimer->isActive())
    {
        sortTimer->setInterval(
            101 - value
            );
    }
}

int MainWindow::partitionOperations(
    std::vector<int>& tempArr,
    int low,
    int high)
{
    int pivot = tempArr[high];

    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(tempArr[j] < pivot)
        {
            i++;

            std::swap(
                tempArr[i],
                tempArr[j]);

            if(i != j)
            {
                quickOperations.push_back({i, j});
            }
        }
    }

    std::swap(
        tempArr[i+1],
        tempArr[high]);

    if(i + 1 != high)
    {
        quickOperations.push_back({i + 1, high});
    }

    return i + 1;
}

void MainWindow::generateQuickSortOperations(
    std::vector<int>& tempArr,
    int low,
    int high)
{
    if(low < high)
    {
        int pi =
            partitionOperations(
                tempArr,
                low,
                high);

        generateQuickSortOperations(
            tempArr,
            low,
            pi - 1);

        generateQuickSortOperations(
            tempArr,
            pi + 1,
            high);
    }
}

void MainWindow::mergeOperationHelper(
    std::vector<int>& tempArr,
    int left,
    int mid,
    int right)
{
    std::vector<int> temp;

    int i = left;
    int j = mid + 1;

    while(i <= mid && j <= right)
    {
        if(tempArr[i] <= tempArr[j])
        {
            temp.push_back(tempArr[i++]);
        }
        else
        {
            temp.push_back(tempArr[j++]);
        }
    }

    while(i <= mid)
        temp.push_back(tempArr[i++]);

    while(j <= right)
        temp.push_back(tempArr[j++]);

    for(int k = 0; k < static_cast<int>(temp.size()); k++)
    {
        tempArr[left + k] = temp[k];

        mergeOperations.push_back(
            {left + k, temp[k]});
    }
}

void MainWindow::generateMergeSortOperations(
    std::vector<int>& tempArr,
    int left,
    int right)
{
    if(left >= right)
        return;

    int mid = (left + right) / 2;

    generateMergeSortOperations(
        tempArr,
        left,
        mid);

    generateMergeSortOperations(
        tempArr,
        mid + 1,
        right);

    mergeOperationHelper(
        tempArr,
        left,
        mid,
        right);
}

void MainWindow::heapifyOperations(
    std::vector<int>& tempArr,
    int n,
    int i)
{
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n &&
        tempArr[left] > tempArr[largest])
    {
        largest = left;
    }

    if(right < n &&
        tempArr[right] > tempArr[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        std::swap(
            tempArr[i],
            tempArr[largest]);

        heapOperations.push_back(
            {i, largest});

        heapifyOperations(
            tempArr,
            n,
            largest);
    }
}

void MainWindow::generateHeapOperations(
    std::vector<int>& tempArr)
{
    int n = static_cast<int>(tempArr.size());

    for(int i = n / 2 - 1;
         i >= 0;
         i--)
    {
        heapifyOperations(
            tempArr,
            n,
            i);
    }

    for(int i = n - 1;
         i > 0;
         i--)
    {
        std::swap(
            tempArr[0],
            tempArr[i]);

        heapOperations.push_back(
            {0, i});

        heapifyOperations(
            tempArr,
            i,
            0);
    }
}

void MainWindow::linearSearchStep()
{
    if(searchIndex >= static_cast<int>(arr.size()))
    {
        sortTimer->stop();

        ui->lblExecutionTime->setText(
            "Not Found (" +
            QString::number(elapsedTimer.elapsed()) +
            " ms)");

        compareIndex1 = -1;
        compareIndex2 = -1;
        foundIndex = -1;
        swapIndex1 = -1;
        swapIndex2 = -1;
        ui->lblFoundIndex->setText(
            "Found Index: -");
        drawBars();
        return;
    }

    compareIndex1 = searchIndex;
    compareIndex2 = -1;
    comparisons++;

    ui->lblSearchComparisons->setText(
        "Search Comparisons: " +
        QString::number(comparisons));

    ui->lblComparisons->setText(
        "Comparisons: " +
        QString::number(comparisons));

    if(arr[searchIndex] == targetValue)
    {
        sortTimer->stop();

        ui->lblExecutionTime->setText(
            "Found at index " +
            QString::number(searchIndex) +
            " in " +
            QString::number(elapsedTimer.elapsed()) +
            " ms");

        foundIndex = searchIndex;
        compareIndex1 = -1;
        compareIndex2 = -1;

        swapIndex1 = -1;
        swapIndex2 = -1;
        ui->lblFoundIndex->setText(
            "Found Index: " +
            QString::number(searchIndex));
        drawBars();
        return;
    }

    ui->lblFoundIndex->setText(
        "Found Index: -");

    drawBars();

    searchIndex++;
}

void MainWindow::binarySearchStep()
{
    if(binaryLeft > binaryRight)
    {
        sortTimer->stop();

        ui->lblExecutionTime->setText(
            "Not Found (" +
            QString::number(elapsedTimer.elapsed()) +
            " ms)");

        compareIndex1 = -1;
        compareIndex2 = -1;
        foundIndex = -1;
        swapIndex1 = -1;
        swapIndex2 = -1;
        ui->lblFoundIndex->setText(
            "Found Index: -");
        drawBars();
        return;
    }

    binaryMid =
        (binaryLeft + binaryRight) / 2;

    compareIndex1 = binaryMid;
    compareIndex2 = -1;
    comparisons++;

    ui->lblSearchComparisons->setText(
        "Search Comparisons: " +
        QString::number(comparisons));
    ui->lblComparisons->setText(
        "Comparisons: " +
        QString::number(comparisons));

    if(arr[binaryMid] == targetValue)
    {
        sortTimer->stop();

        ui->lblExecutionTime->setText(
            "Found at index " +
            QString::number(binaryMid) +
            " in " +
            QString::number(elapsedTimer.elapsed()) +
            " ms");

        foundIndex = binaryMid;
        compareIndex1 = -1;
        compareIndex2 = -1;

        swapIndex1 = -1;
        swapIndex2 = -1;
        ui->lblFoundIndex->setText(
            "Found Index: " +
            QString::number(binaryMid));
        drawBars();
        return;
    }

    if(arr[binaryMid] < targetValue)
    {
        binaryLeft = binaryMid + 1;
    }
    else
    {
        binaryRight = binaryMid - 1;
    }

    ui->lblFoundIndex->setText(
        "Found Index: -");

    drawBars();
}

void MainWindow::createGraph()
{
    graph.clear();

    graph.resize(7);

    graph[0] = {1,2};
    graph[1] = {0,3,4};
    graph[2] = {0,5,6};
    graph[3] = {1};
    graph[4] = {1};
    graph[5] = {2};
    graph[6] = {2};

    nodePositions.clear();

    nodePositions.push_back(QPointF(300,50));   // 0
    nodePositions.push_back(QPointF(180,150));  // 1
    nodePositions.push_back(QPointF(420,150));  // 2
    nodePositions.push_back(QPointF(120,280));  // 3
    nodePositions.push_back(QPointF(240,280));  // 4
    nodePositions.push_back(QPointF(360,280));  // 5
    nodePositions.push_back(QPointF(480,280));  // 6
}

void MainWindow::drawGraph()
{
    scene->clear();

    for(int i = 0;
         i < static_cast<int>(graph.size());
         i++)
    {
        for(int neighbour : graph[i])
        {
            if(i < neighbour)
            {
                QPen edgePen(Qt::black);

                for(const auto& edge : mstEdges)
                {
                    if((edge.first == i &&
                         edge.second == neighbour) ||

                        (edge.first == neighbour &&
                         edge.second == i))
                    {
                        edgePen.setColor(Qt::green);
                        edgePen.setWidth(3);
                    }
                }

                for(const auto& edge : primEdges)
                {
                    if((edge.first == i &&
                         edge.second == neighbour) ||

                        (edge.first == neighbour &&
                         edge.second == i))
                    {
                        edgePen.setColor(Qt::green);
                        edgePen.setWidth(3);
                    }
                }

                scene->addLine(
                    nodePositions[i].x(),
                    nodePositions[i].y(),
                    nodePositions[neighbour].x(),
                    nodePositions[neighbour].y(),
                    edgePen
                    );
            }
        }
    }

    for(int i = 0;
         i < static_cast<int>(graph.size());
         i++)
    {
        QColor color = Qt::blue;

        bool dfsVisited =
            i < static_cast<int>(visitedDFS.size()) &&
            visitedDFS[i];

        bool bfsVisited =
            i < static_cast<int>(visitedBFS.size()) &&
            visitedBFS[i];

        bool dijkstraVisited =
            i < static_cast<int>(visitedDijkstra.size()) &&
            visitedDijkstra[i];

        bool primVisited =
            i < static_cast<int>(visitedPrim.size()) &&
            visitedPrim[i];

        bool topoVisited = false;

        for(int k = 0;
             k < topoIndex &&
             k < static_cast<int>(topoOrder.size());
             k++)
        {
            if(topoOrder[k] == i)
            {
                topoVisited = true;
                break;
            }
        }

        if(dfsVisited ||
            bfsVisited ||
            dijkstraVisited ||
            primVisited ||
            topoVisited)
        {
            color = Qt::green;
        }

        if(i == currentDFSNode ||
            i == currentBFSNode ||
            i == currentDijkstraNode ||
            i == currentPrimNode ||
            i == currentTopoNode)
        {
            color = Qt::red;
        }

        scene->addEllipse(
            nodePositions[i].x()-20,
            nodePositions[i].y()-20,
            40,
            40,
            QPen(Qt::black),
            QBrush(color)
            );

        QString label =
            QString::number(i);

        if(!distances.empty() &&
            i < static_cast<int>(distances.size()) &&
            distances[i] != INT_MAX)
        {
            label +=
                "\n" +
                QString::number(distances[i]);
        }

        if(!topoOrder.empty())
        {
            for(int k = 0;
                 k < topoIndex &&
                 k < static_cast<int>(topoOrder.size());
                 k++)
            {
                if(topoOrder[k] == i)
                {
                    label += "\n#" +
                             QString::number(k + 1);

                    break;
                }
            }
        }

        scene->addText(label)
            ->setPos(
                nodePositions[i].x()-10,
                nodePositions[i].y()-15);
    }
}

void MainWindow::dfsStep()
{
    if(dfsStack.empty())
    {
        sortTimer->stop();

        ui->lblExecutionTime->setText(
            "DFS Completed in " +
            QString::number(elapsedTimer.elapsed()) +
            " ms");
        ui->lblFoundIndex->setText(
            "Visited Nodes: " +
            QString::number(comparisons));
        ui->lblSearchComparisons->setText(
            "DFS Visits: " +
            QString::number(comparisons));

        currentDFSNode = -1;
        sortingFinished = true;
        drawGraph();
        return;
    }

    int node = dfsStack.top();
    dfsStack.pop();

    currentDFSNode = node;

    if(!visitedDFS[node])
    {
        comparisons++;

        ui->lblSearchComparisons->setText(
            "DFS Visits: " +
            QString::number(comparisons));
        ui->lblComparisons->setText(
            "Comparisons: " +
            QString::number(comparisons));
        visitedDFS[node] = true;

        for(auto it = graph[node].rbegin();
             it != graph[node].rend();
             ++it)
        {
            if(!visitedDFS[*it])
            {
                dfsStack.push(*it);
            }
        }
    }

    drawGraph();
}

void MainWindow::bfsStep()
{
    if(bfsQueue.empty())
    {
        sortTimer->stop();

        ui->lblExecutionTime->setText(
            "BFS Completed in " +
            QString::number(
                elapsedTimer.elapsed()) +
            " ms"
            );

        ui->lblFoundIndex->setText(
            "Visited Nodes: " +
            QString::number(comparisons)
            );
        ui->lblSearchComparisons->setText(
            "BFS Visits: " +
            QString::number(comparisons));

        currentBFSNode = -1;

        sortingFinished = true;

        drawGraph();

        return;
    }

    int node = bfsQueue.front();
    bfsQueue.pop();

    currentBFSNode = node;

    comparisons++;

    for(int neighbour : graph[node])
    {
        if(!visitedBFS[neighbour])
        {
            visitedBFS[neighbour] = true;
            bfsQueue.push(neighbour);
        }
    }

        ui->lblSearchComparisons->setText(
            "BFS Visits: " +
            QString::number(comparisons)
            );

        ui->lblComparisons->setText(
            "Comparisons: " +
            QString::number(comparisons)
            );

    drawGraph();
}

void MainWindow::createTree()
{
    if(root != nullptr)
    {
        deleteTree(root);
        root = nullptr;
    }

    root = new TreeNode{1,nullptr,nullptr};

    root->left =
        new TreeNode{2,nullptr,nullptr};

    root->right =
        new TreeNode{3,nullptr,nullptr};

    root->left->left =
        new TreeNode{4,nullptr,nullptr};

    root->left->right =
        new TreeNode{5,nullptr,nullptr};

    root->right->left =
        new TreeNode{6,nullptr,nullptr};

    root->right->right =
        new TreeNode{7,nullptr,nullptr};
}

void MainWindow::preorderStep()
{
    if(traversalIndex >= traversalOrder.size())
    {
        sortTimer->stop();

        currentTreeNode = -1;

        ui->lblExecutionTime->setText(
            "Traversal Completed in " +
            QString::number(
                elapsedTimer.elapsed()) +
            " ms");
        ui->lblFoundIndex->setText(
            "Visited Nodes: " +
            QString::number(comparisons));
        ui->lblSearchComparisons->setText(
            "Visited Nodes: " +
            QString::number(comparisons));

        drawTree();
        return;
    }

    currentTreeNode =
        traversalOrder[traversalIndex];

    comparisons++;

    ui->lblSearchComparisons->setText(
        "Visited Nodes: " +
        QString::number(comparisons));

    ui->lblComparisons->setText(
        "Comparisons: " +
        QString::number(comparisons));

    ui->lblFoundIndex->setText(
        "Current Node: " +
        QString::number(currentTreeNode));

    traversalIndex++;

    drawTree();
}

void MainWindow::preorderTraversal(
    TreeNode* node)
{
    if(!node)
        return;

    traversalOrder.push_back(
        node->value);

    preorderTraversal(
        node->left);

    preorderTraversal(
        node->right);
}

void MainWindow::inorderStep()
{
    if(traversalIndex >= traversalOrder.size())
    {
        sortTimer->stop();

        currentTreeNode = -1;

        ui->lblExecutionTime->setText(
            "Traversal Completed in " +
            QString::number(
                elapsedTimer.elapsed()) +
            " ms");
        ui->lblFoundIndex->setText(
            "Visited Nodes: " +
            QString::number(comparisons));
        ui->lblSearchComparisons->setText(
            "Visited Nodes: " +
            QString::number(comparisons));

        drawTree();
        return;
    }

    currentTreeNode =
        traversalOrder[traversalIndex];

    comparisons++;

    ui->lblSearchComparisons->setText(
        "Visited Nodes: " +
        QString::number(comparisons));

    ui->lblComparisons->setText(
        "Comparisons: " +
        QString::number(comparisons));

    ui->lblFoundIndex->setText(
        "Current Node: " +
        QString::number(currentTreeNode));

    traversalIndex++;

    drawTree();
}

void MainWindow::inorderTraversal(
    TreeNode* node)
{
    if(!node)
        return;

    inorderTraversal(
        node->left);

    traversalOrder.push_back(
        node->value);

    inorderTraversal(
        node->right);
}

void MainWindow::postorderStep()
{
    if(traversalIndex >= traversalOrder.size())
    {
        sortTimer->stop();

        currentTreeNode = -1;

        ui->lblExecutionTime->setText(
            "Traversal Completed in " +
            QString::number(
                elapsedTimer.elapsed()) +
            " ms");
        ui->lblFoundIndex->setText(
            "Visited Nodes: " +
            QString::number(comparisons));
        ui->lblSearchComparisons->setText(
            "Visited Nodes: " +
            QString::number(comparisons));

        drawTree();
        return;
    }

    currentTreeNode =
        traversalOrder[traversalIndex];

    comparisons++;

    ui->lblSearchComparisons->setText(
        "Visited Nodes: " +
        QString::number(comparisons));

    ui->lblComparisons->setText(
        "Comparisons: " +
        QString::number(comparisons));

    ui->lblFoundIndex->setText(
        "Current Node: " +
        QString::number(currentTreeNode));

    traversalIndex++;

    drawTree();
}

void MainWindow::postorderTraversal(
    TreeNode* node)
{
    if(!node)
        return;

    postorderTraversal(
        node->left);

    postorderTraversal(
        node->right);

    traversalOrder.push_back(
        node->value);
}

void MainWindow::levelOrderStep()
{
    if(traversalIndex >= traversalOrder.size())
    {
        sortTimer->stop();

        currentTreeNode = -1;

        ui->lblExecutionTime->setText(
            "Traversal Completed in " +
            QString::number(
                elapsedTimer.elapsed()) +
            " ms");
        ui->lblFoundIndex->setText(
            "Visited Nodes: " +
            QString::number(comparisons));
        ui->lblSearchComparisons->setText(
            "Visited Nodes: " +
            QString::number(comparisons));

        drawTree();
        return;
    }

    currentTreeNode =
        traversalOrder[traversalIndex];

    comparisons++;

    ui->lblSearchComparisons->setText(
        "Visited Nodes: " +
        QString::number(comparisons));

    ui->lblComparisons->setText(
        "Comparisons: " +
        QString::number(comparisons));

    ui->lblFoundIndex->setText(
        "Current Node: " +
        QString::number(currentTreeNode));

    traversalIndex++;

    drawTree();
}

void MainWindow::levelOrderTraversal(
    TreeNode* node)
{
    if(!node)
        return;

    std::queue<TreeNode*> q;

    q.push(node);

    while(!q.empty())
    {
        TreeNode* current =
            q.front();

        q.pop();

        traversalOrder.push_back(
            current->value);

        if(current->left)
            q.push(
                current->left);

        if(current->right)
            q.push(
                current->right);
    }
}

void MainWindow::drawTree()
{
    scene->clear();

    std::vector<QPointF> pos =
        {
            QPointF(300,50),
            QPointF(200,150),
            QPointF(400,150),
            QPointF(150,250),
            QPointF(250,250),
            QPointF(350,250),
            QPointF(450,250)
        };

    scene->addLine(300,50,200,150);
    scene->addLine(300,50,400,150);

    scene->addLine(200,150,150,250);
    scene->addLine(200,150,250,250);

    scene->addLine(400,150,350,250);
    scene->addLine(400,150,450,250);

    for(int node = 1; node <= 7; node++)
    {
        QColor color = Qt::blue;

        bool visited = false;

        for(int k = 0;
             k < traversalIndex &&
             k < static_cast<int>(traversalOrder.size());
             k++)
        {
            if(traversalOrder[k] == node)
            {
                visited = true;
                break;
            }
        }

        if(visited)
        {
            color = Qt::green;
        }

        if(node == currentTreeNode)
        {
            color = Qt::red;
        }

        scene->addEllipse(
            pos[node - 1].x() - 20,
            pos[node - 1].y() - 20,
            40,
            40,
            QPen(Qt::black),
            QBrush(color));

        scene->addText(
                 QString::number(node))
            ->setPos(
                pos[node - 1].x() - 5,
                pos[node - 1].y() - 10);
    }
}

void MainWindow::dijkstraStep()
{
    int n =
        static_cast<int>(graph.size());

    int minDistance = INT_MAX;

    int u = -1;

    for(int i = 0; i < n; i++)
    {
        if(!visitedDijkstra[i] &&
            distances[i] < minDistance)
        {
            minDistance =
                distances[i];

            u = i;
        }
    }

    if(u == -1)
    {
        sortTimer->stop();

        currentDijkstraNode = -1;

        ui->lblExecutionTime->setText(
            "Dijkstra Completed in " +
            QString::number(
                elapsedTimer.elapsed()) +
            " ms");
        ui->lblFoundIndex->setText(
            "Visited Nodes: " +
            QString::number(comparisons));

        ui->lblSearchComparisons->setText(
            "Dijkstra Visits: " +
            QString::number(comparisons));

        drawGraph();
        return;
    }

    currentDijkstraNode = u;

    visitedDijkstra[u] = true;

    comparisons++;

    ui->lblSearchComparisons->setText(
        "Dijkstra Visits: " +
        QString::number(comparisons));

    ui->lblComparisons->setText(
        "Comparisons: " +
        QString::number(comparisons));

    for(int neighbour : graph[u])
    {
        if(!visitedDijkstra[neighbour])
        {
            const int weight = 1;

            if(distances[u] + weight < distances[neighbour])
            {
                distances[neighbour] =
                    distances[u] + weight;
            }
        }
    }

    drawGraph();
}

void MainWindow::primStep()
{
    int n =
        static_cast<int>(graph.size());

    int nextNode = -1;

    if(comparisons == 0)
    {
        nextNode = 0;
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(visitedPrim[i])
            {
                for(int neighbour : graph[i])
                {
                    if(!visitedPrim[neighbour])
                    {
                        nextNode = neighbour;
                        break;
                    }
                }
            }

            if(nextNode != -1)
                break;
        }
    }

    if(nextNode == -1)
    {
        sortTimer->stop();

        currentPrimNode = -1;

        ui->lblExecutionTime->setText(
            "Prim MST Completed in " +
            QString::number(
                elapsedTimer.elapsed()) +
            " ms");

        ui->lblFoundIndex->setText(
            "MST Nodes: " +
            QString::number(comparisons));

        ui->lblSearchComparisons->setText(
            "Prim Visits: " +
            QString::number(comparisons));

        drawGraph();
        return;
    }

    currentPrimNode = nextNode;

    for(int i = 0; i < n; i++)
    {
        if(visitedPrim[i])
        {
            for(int neighbour : graph[i])
            {
                if(neighbour == nextNode)
                {
                    primEdges.push_back({i, nextNode});
                    break;
                }
            }
        }
    }

    visitedPrim[nextNode] = true;

    comparisons++;

    ui->lblComparisons->setText(
        "Comparisons: " +
        QString::number(comparisons));

    ui->lblSearchComparisons->setText(
        "Prim Visits: " +
        QString::number(comparisons));

    ui->lblFoundIndex->setText(
        "Current Node: " +
        QString::number(nextNode));

    drawGraph();
}

void MainWindow::kruskalStep()
{
    static std::vector<std::pair<int,int>> allEdges;

    if(kruskalEdgeIndex == 0 &&
        allEdges.empty())
    {
        for(int i = 0;
             i < static_cast<int>(graph.size());
             i++)
        {
            for(int neighbor : graph[i])
            {
                if(i < neighbor)
                {
                    allEdges.push_back(
                        {i, neighbor});
                }
            }
        }
    }

    if(kruskalEdgeIndex >=
        static_cast<int>(allEdges.size()))
    {
        sortTimer->stop();

        ui->lblExecutionTime->setText(
            "Kruskal MST Completed in " +
            QString::number(
                elapsedTimer.elapsed()) +
            " ms");

        ui->lblFoundIndex->setText(
            "MST Edges: " +
            QString::number(
                mstEdges.size()));

        drawGraph();

        allEdges.clear();

        return;
    }

    auto edge = allEdges[kruskalEdgeIndex];

    int u = edge.first;
    int v = edge.second;

    if(findSet(u) != findSet(v))
    {
        mstEdges.push_back(edge);
        unionSet(u,v);
    }

    comparisons++;

    ui->lblComparisons->setText(
        "Comparisons: " +
        QString::number(comparisons));

    ui->lblSearchComparisons->setText(
        "Edges Added: " +
        QString::number(
            mstEdges.size()));

    ui->lblFoundIndex->setText(
        "Current Edge: (" +
        QString::number(
            allEdges[kruskalEdgeIndex].first)
        + ", " +
        QString::number(
            allEdges[kruskalEdgeIndex].second)
        + ")");

    kruskalEdgeIndex++;

    drawGraph();
}

void MainWindow::topologicalSortStep()
{
    if(topoIndex >=
        static_cast<int>(topoOrder.size()))
    {
        sortTimer->stop();

        currentTopoNode = -1;

        ui->lblExecutionTime->setText(
            "Topological Sort Completed in " +
            QString::number(
                elapsedTimer.elapsed()) +
            " ms");

        ui->lblFoundIndex->setText(
            "Order Length: " +
            QString::number(
                topoOrder.size()));

        ui->lblSearchComparisons->setText(
            "Processed Nodes: " +
            QString::number(
                topoOrder.size()));

        drawGraph();

        return;
    }

    currentTopoNode =
        topoOrder[topoIndex];

    comparisons++;

    ui->lblComparisons->setText(
        "Comparisons: " +
        QString::number(comparisons));

    ui->lblSearchComparisons->setText(
        "Processed Nodes: " +
        QString::number(comparisons));

    ui->lblFoundIndex->setText(
        "Current Node: " +
        QString::number(
            currentTopoNode));

    topoIndex++;

    drawGraph();
}