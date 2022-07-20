
// Given Matrix representing black and white pixels of image
// Back pixel -> 1
// White pixel -> 0

// Sample input:

// 1 0 0 0 0 0
// 0 1 0 1 1 1
// 0 0 1 0 1 0
// 1 1 0 0 1 0
// 1 0 1 1 0 0
// 1 0 0 0 0 1

// Islands removed are marked by x:

// 1 0 0 0 0 0
// 0 x 0 1 1 1
// 0 0 x 0 1 0
// 1 1 0 0 1 0
// 1 0 x x 0 0
// 1 0 0 0 0 1

// Sample output

// Remove black pixels not connected to boundary of image.
// 2 or more pixles adjacent vertically or horizontally are connected.

#include <vector>
#include <queue>
#include <ctype.h>
#include <iostream>

typedef std::vector<std::vector<int> > matrix;

struct Pixel
{
    int row;
    int col;
};

enum PixelType
{
    WHITE,
    BLACK,
    VISITED
};

// pixels can be connected in these directions
const Pixel dirs[4] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}};

void printMatrix(const matrix &image)
{
    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j < image[i].size(); j++)
        {
            std::cout << image[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

bool validPixel(Pixel p, const matrix &image)
{
    return p.row >= 0 && p.row < image.size() &&
           p.col >= 0 && p.col < image[0].size();
}

void logBoundaryPixel(Pixel p)
{
    std::cout << "Found boundary pixel at: " << p.row << "," << p.col << std::endl;
}

void printQueue(std::queue<Pixel> q)
{
    std::cout << "Queue size: " << q.size() << std::endl;
    while (!q.empty())
    {
        Pixel p = q.front();
        std::cout << "(" << p.row << ", " << p.col << ") ";
        q.pop();
    }
    std::cout << std::endl;
}

bool isVisited(Pixel p, const matrix &image)
{
    return image[p.row][p.col] == VISITED;
}

void visit(Pixel p, matrix &image)
{
    image[p.row][p.col] = VISITED;
}

bool isBlackPixel(Pixel p, const matrix &image)
{
    return image[p.row][p.col] == BLACK;
}

void removeIslands(matrix &image)
{
    int numRows = image.size();
    int numCols = image[0].size();

    if (numRows == 0 || numCols == 0)
    {
        return;
    }

    std::queue<Pixel> *q = new std::queue<Pixel>();

    // Get the boundary ones from image and add them to queue.

    for (int col = 0; col < numCols; col++)
    {
        // Top row
        if (image[0][col] == BLACK)
        {
            Pixel p = {0, col};
            q->push(p);
            logBoundaryPixel(p);
        }

        // Bottom row
        if (image[numRows - 1][col] == BLACK)
        {
            Pixel p = {numRows - 1, col};
            q->push(p);
            logBoundaryPixel(p);
        }
    }

    for (int row = 0; row < numRows; row++)
    {
        // Left col
        if (image[row][0] == BLACK)
        {
            Pixel p = {row, 0};
            q->push(p);
            logBoundaryPixel(p);
        }

        // Right col
        if (image[row][numCols - 1] == BLACK)
        {
            Pixel p = {row, numCols - 1};
            q->push(p);
            logBoundaryPixel(p);
        }
    }

    // Visit the boundary ones and their connected pixels.
    while (!q->empty())
    {
        std::cout << "Finding connected pixels...\n"
                  << std::endl;
        printQueue(*q);

        Pixel bpxl = q->front();
        q->pop();

        if (!isVisited(bpxl, image))
        {
            for (int i = 0; i < 4; i++)
            {
                Pixel dir = dirs[i];
                Pixel neighbour = {bpxl.row + dir.row, bpxl.col + dir.col};

                if (validPixel(neighbour, image) && isBlackPixel(neighbour, image))
                {
                    visit(bpxl, image);
                    q->push(neighbour);
                }
            }
        }
    }

    std::cout << "Visit boundary pixels complete...\n"
              << std::endl;
    printMatrix(image);

    // All boundary pixels have been set to VISITED state.
    // Find remaining ones, which are the islands, and set them to 0.
    // Set the visited back to 1.

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            if (image[i][j] == VISITED)
            {
                image[i][j] = BLACK;
            }
            else if (image[i][j] == BLACK)
            {
                image[i][j] = WHITE;
            }
        }
    }

    delete q;
}

int main()
{
    // std::string rows[] = {"1 0 0 0 0 0",
    //                       "0 1 0 1 1 1",
    //                       "0 0 1 0 1 0",
    //                       "1 1 0 0 1 0",
    //                       "1 0 1 1 0 0",
    //                       "1 0 0 0 0 1"};

    std::vector<std::string> rows;

    rows.push_back("1 0 1 0");
    rows.push_back("0 1 0 0");
    rows.push_back("1 0 1 0");
    rows.push_back("1 0 1 1");

    matrix image;

    for (int row = 0; row < rows.size(); row++)
    {
        std::vector<int> rowVector;

        std::string cols = rows[row];

        for (int col = 0; col < cols.size(); col++)
        {
            char c = cols[col];

            if (isdigit(c))
            {
                int value = c - '0';
                rowVector.push_back(value);
            }
        }

        image.push_back(rowVector);
    }

    std::cout << "Input\n"
              << std::endl;
    printMatrix(image);

    removeIslands(image);

    std::cout << "Output\n"
              << std::endl;
    printMatrix(image);

    return 0;
}