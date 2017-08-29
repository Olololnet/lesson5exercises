#include <iostream>

void ArrayReverse(int* szArray, int iCurrentStartIndex, int iCurrentEndIndex)
{
    if ((iCurrentStartIndex - iCurrentEndIndex) <= 0)
        return;

    int iNumberCopy = szArray[iCurrentStartIndex];

    szArray[iCurrentStartIndex] = szArray[iCurrentEndIndex];
    szArray[iCurrentEndIndex]   = iNumberCopy;

    ArrayReverse(szArray, iCurrentStartIndex - 1, iCurrentEndIndex + 1);
}

void Exercise6()
{
    //Exercise6: Перевернуть массив с помощью рекурсивной функции

    int szArray[] = {1, 2, 3, 4, 5, 6, 7};
    int iElementsCount = sizeof(szArray)/sizeof(int);

    ArrayReverse(szArray, iElementsCount - 1, 0);

    for (int i = 0; i < iElementsCount; i++)
    {
        std::cout << szArray[i] << std::endl;
    }
}

int FindSecondMinimum(int* szArray, int iCurIndex, int iMinimum, int iSecondMinimum)
{
    if (iCurIndex < 0)
        return iSecondMinimum;

    if ((szArray[iCurIndex] < iSecondMinimum) && (szArray[iCurIndex] != iMinimum))
        iSecondMinimum = szArray[iCurIndex];

    return FindSecondMinimum(szArray, --iCurIndex, iMinimum, iSecondMinimum);
}

int FindMinumum(int* szArray, int iCurIndex, int iMinimum)
{
    if (iCurIndex < 0)
        return iMinimum;

    if (szArray[iCurIndex] < iMinimum)
        iMinimum = szArray[iCurIndex];

    return FindMinumum(szArray, --iCurIndex, iMinimum);
}

int FindMaximum(int* szArray, int iCurIndex, int iMaximum)
{
    if (iCurIndex < 0)
        return iMaximum;

    if (szArray[iCurIndex] > iMaximum)
        iMaximum = szArray[iCurIndex];

    return FindMaximum(szArray, --iCurIndex, iMaximum);
}

void Exercise5()
{
    // Exercise5: Найти в массиве второй минимум

    int szArray[] = {10, 7, 2, 7, 11, 13, 5, 10};
    int iElementsCount = sizeof(szArray)/sizeof(int);

    int iMaxIndex = iElementsCount - 1;

    int iMinimum = FindMinumum(szArray, iMaxIndex, szArray[iMaxIndex]);
    int iMaximum = FindMaximum(szArray, iMaxIndex, szArray[iMaxIndex]);

    std::cout << FindSecondMinimum(szArray, iMaxIndex, iMinimum, iMaximum);
}

int FindFibNumber(int* szFibArray, int iCurIndex, int iRequiredIndex)
{
    if (iCurIndex == 0)
        szFibArray[iCurIndex] = 0;
    else if (iCurIndex == 1)
        szFibArray[iCurIndex] = 1;
    else
        szFibArray[iCurIndex] = szFibArray[iCurIndex - 2] + szFibArray[iCurIndex - 1];

    if (iCurIndex == iRequiredIndex)
        return szFibArray[iCurIndex];
    else
        return FindFibNumber(szFibArray, ++iCurIndex, iRequiredIndex);
}

void Exercise4()
{
    //Exercise4: Переписать алгоритм нахождения чисел Фибоначчи на массив

    int iCount = 0;
    std::cout << "Enter Fibonacci index to find number:" << std::endl;
    std::cin >> iCount;

    if (iCount <= 0)
    {
        std::cout << "Wrong input";
        return;
    }

    int* szFibArray = new int[iCount];

    std::cout << FindFibNumber(szFibArray, 0, (iCount - 1));

    delete[] szFibArray;
}

void PrintReverseNumber(int iNumber)
{
    if (iNumber)
    {
        std::cout << iNumber%10;
        PrintReverseNumber(iNumber/10);
    }
}

void Exercise3()
{
    //Exercise3: Вывести число в обратном порядке: 1234 -> 4321 (рек)

    int iInput = 0;
    std::cout << "Enter number to reverse" << std::endl;
    std::cin >> iInput;

    PrintReverseNumber(iInput);
}


int PowConverter(int iBaseNum, int iPower, int iBaseCopy)
{
    if (iPower > 1)
    {
        iBaseNum *= iBaseCopy;
        iPower--;
    }
    else
        return iBaseNum;

    return PowConverter(iBaseNum, iPower, iBaseCopy);
}


int CustomPow(int iBaseNum, int iPower)
{
    if (!iPower)
        return 1;

    return PowConverter(iBaseNum, iPower, iBaseNum);
}

void Exercise2()
{
    //Exercise2: Написать функцию для вычисления степени числа: pow (a, b)

    std::cout << CustomPow(2, 3);
}


void PrintEvenIndex(int* szIntArray, int iCurrentElement)
{
    if (iCurrentElement < 0)
        return;

    if (!(szIntArray[iCurrentElement]%2))
        std::cout << szIntArray[iCurrentElement] << std::endl;

    PrintEvenIndex(szIntArray, iCurrentElement - 1);
}


void Exercise1()
{
    // Exercise1: Написать функцию печати всех чётных элементов массива (рек)

    int szIntArray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int iElementsCount = sizeof(szIntArray)/sizeof(int);

    PrintEvenIndex(szIntArray, iElementsCount - 1);
}

void ExerciseOnLesson()
{
    // ExerciseOnLesson: Даны два упорядоченных массива одного размера. Требуется "слить" эти два массива в третий,
    // чтобы элементы находились в нём в упорядоченном состоянии. 1 2 6 8, 4 5 6 9 -> 1 2 4 5 6 6 8 9

    int szIntArray1[] = {1, 2, 6, 8};
    int szIntArray2[] = {4, 5, 6, 9};
    int iArray1Elements = sizeof(szIntArray1)/sizeof(int);
    int iArray2Elements = sizeof(szIntArray2)/sizeof(int);

    int iCurrentIndex1Arr = 0, iCurrentIndex2Arr = 0, iCurrentInt = 0;
    int iElementsCount = iArray1Elements + iArray2Elements;
    int* szIntArrayFull = new int[iElementsCount];

    for (int i = 0; i < iElementsCount; i++)
    {
        if (iCurrentIndex1Arr < iArray1Elements && iCurrentIndex2Arr < iArray2Elements)
        {
            if (szIntArray1[iCurrentIndex1Arr] < szIntArray2[iCurrentIndex2Arr])
            {
                iCurrentInt = szIntArray1[iCurrentIndex1Arr];
                iCurrentIndex1Arr++;
            }
            else
            {
                iCurrentInt = szIntArray2[iCurrentIndex2Arr];
                iCurrentIndex2Arr++;
            }
        }
        else if (iCurrentIndex1Arr == iArray1Elements)
        {
            iCurrentInt = szIntArray2[iCurrentIndex2Arr];
            iCurrentIndex2Arr++;
        }
        else if (iCurrentIndex2Arr == iArray2Elements)
        {
            iCurrentInt = szIntArray1[iCurrentIndex1Arr];
            iCurrentIndex1Arr++;
        }

        szIntArrayFull[i] = iCurrentInt;
    }

    for (int i = 0; i < iElementsCount; i++)
        std::cout << szIntArrayFull[i] << std::endl;

    delete[] szIntArrayFull;
}


int main()
{

//    ExerciseOnLesson();
//    Exercise1();
//    Exercise2();
//    Exercise3();
//    Exercise4();
//    Exercise5();
//    Exercise6();

    return 0;
}
