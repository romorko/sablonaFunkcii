#include <iostream>

template<typename Any>
int cmp(const void *a, const void *b);

template<typename Any>
void swap(Any &a , Any &b);

template<typename T>
void swap(T *a, T *b, int pocet);

int main()
{
/*    int x = 5;
    int y = 10;
    swap<int>(x, y);
    float m = 1.3;
    float n = 0.45;
    swap<float>(m, n);
    char p = 'p';
    char r = 'r';
    swap<char>(p, r);*/
    int pole1[]{0, 2, 3};
    int pole2[]{4, 5, 6};
    for (auto i: pole1)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    qsort(pole1,3,sizeof(pole1[0]),cmp<int>);
    for (auto i: pole1)
    {
        std::cout << i << " ";
    }
    swap<int>(pole1, pole2, 3);
    for (auto i: pole1)
    {
        std::cout << i << " ";
    }
    return 0;
}

template<typename Any>
void swap(Any &a, Any &b)
{
    Any temp = a;
    a = b;
    b = temp;
}

template<typename T>
void swap(T *a, T *b, int pocet)
{
    T temp;
    for (int i = 0; i < pocet; ++i)
    {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }

}

template<typename Any>
int cmp(const void *a, const void *b)
{
    Any *prvy = (Any *) a;
    Any *druhy = (Any *) b;
    return (*prvy)<(*druhy)?1:(*prvy)>(*druhy)?-1:0;
}