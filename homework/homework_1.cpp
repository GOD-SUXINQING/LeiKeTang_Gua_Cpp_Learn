/*
���γ�˵����ַ
https://www.zhihu.com/question/389457315/answer/1170354190

���γ���Ƶҳ��
https://www.bilibili.com/video/BV1rt4y127ak/

���ڴ���ҵ��Ҫ��������Щ���򶼻�ʹ�� C++ 11 �ı�׼����д


ǰ������ҵ������ʹ�����߱���������ɣ�ʡȴ���û�����ʱ��
�������²���ʹ�����߱�����
1������վ https://www.tutorialspoint.com/compile_cpp11_online.php
2������Ǵ��������ɾ����������
3���ѱ��ļ������ظ��Ƶ��������������
4�����ҳ�����Ͻǵ� Execute ��ť�������г������Ҳ���ʾ���


�� C++ �У�����������ǿ�Ƶ� int main() ����
���ڱ��ļ���ĩβ


C++ ����Ҫ����ͷ�ļ���ʹ��һЩ��
vector �����鹦��
iostream �������������
*/
#include <vector>
#include <iostream>

/*
�������������ط��������� using namespace std; ������
Ҫ����ʽ��ʹ�� using std::out; ���������
��ʵ�������ɶ��и��Ե����ɣ�����ֻ�����������Ͳ�վ��
�ܵ���˵���� .cpp �ļ����� using namespace std; �Ǵ�������ϻ�̵ķ���
��������������

���ڲ��˽� C++ ��ͬѧ��������������
C++ �ı�׼���ȫ�̴������
std::cout
std::endl
std::string
...
����д��̫���ˣ������������������ʡ�� std:: ���ǰ׺����
using namespace std;
*/

using namespace std;

/*
_print �� log ����������
���ڲ���Ҫ����д��
��ʱֻ�赱������ʹ�ñ���
ԭ���� C++ ����Ҫʹ�� cout �����������
cout << "hello" << " " << "world" << endl;

��������ʵ�ڲ��Ǻܷ��㣬�����Ժ��д�ܶ�����������
ÿ�����Զ��и��Բ�ͬ�������ʽ
�ʶ�����ͳһ��װһ�� log ������������÷�����
log("hello", " ", "world");

��Ҳ���ڡ������̡�����ѱ�����ſΡ��н̵ķ�ʽ
https://www.bilibili.com/video/av82386417

�����ҵҪ������һ�����Եı�̻���
���û�У�����ۿ�����ġ������̡�����ѱ�����ſΡ�������������
��һ���� 5 ��
*/
template <class T>
void _print(T arg)
{
    cout << arg << " ";
}

template <class... Args>
void log(Args... args)
{
    int arr[] = {(_print(args), 0)...};
    cout << endl;
}

// ��ҵ��ʽ��ʼ
//
// ���� 1
// ������ĺ�
/*
�� C++ �У����������ע����ֵ���ͣ����������������ע����
sum ������һ������ float ���͵ĺ���
���Ĳ������� array�������� vector<float> &
���� vector<float> ��ʾ������ ���洢 float Ԫ�ص����顱
& ���ű�ʾ���� array ��һ�� �����á�

�����á� ��һ�� C++ �е��¸����ʵ������һ�� C ������ָ����﷨��
������ʱ���ù���������ں�������ҵ�л�ѧ����
���ڼ�ס���� vector ���Ͷ�ʹ�� & �����α�������
 */
float sum(vector<float> &array)
{
    // ������һ������ s ����������ĺ�
    float s = 0;
    // .size() �����ķ���ֵ�� size_t
    // ��������ı��� i Ҳ�� size_t������Ե��� int��
    size_t i = 0;
    // array.size() ��� vector �Ĵ�С
    while (i < array.size())
    {
        float n = array[i];
        s = s + n;
        i = i + 1;
    }
    return s;
}

/*
���ա������̡�����ѱ�����ſΡ��ı�׼
���������ṩһ�����׵Ĳ��Է��������ܸ�ǿ�Ĳ��Է����ں�������ҵ�л������

ensure ������һ������
���Ϊ true ������ �����Գɹ���
���Ϊ false ������ message
�������ǾͿ���֪���Ƿ���Գɹ����Լ������ĸ�����ʧ����

��ÿһ����������Ӧ��дһ�� test ����������������߿���Ч��
*/
void ensure(bool condition, const string &message)
{
    if (condition)
    {
        log("���Գɹ�");
    }
    else
    {
        log(message);
    }
}

void testSum(void)
{
    vector<float> v1 = {1, 2, 3, 4};
    float s1 = sum(v1);
    ensure(s1 == 10, "sum test error 1");
    //
    vector<float> v2 = {1, 2, 3, 4, 5, 6};
    float s2 = sum(v2);
    ensure(s2 == 21, "sum test error 2");
}

// ��ҵ 1
// ������һ��ֻ�������ֵ� array
// �� array �ĳ˻�
// ������������

// ��ʾ��
//     ͨ���������飬Ȼ���۳˵ķ�ʽ��������ĳ˻����ο����� 1
//
// �ֲ���ʾ��
//     1. ������һ������ s ����������ĳ˻�����ʼֵΪ 1
//     2. �������飬�ñ��� n ����Ԫ�ص�ֵ
//     3. �۳�ÿ�εı��� n ������ s
//     4. ѭ�������󣬱��� s ������������������Ԫ�صĳ˻�
//     5. ���ر��� s������Ҫ��һ��Ҫ return s��

float product(vector<float> &array)
{
    float s = 1;
    for (int n = 0; n < array.size(); n++)
    {
        s *= array[n];
    }
    return s;
}

void testProduct(void)
{
    vector<float> v1 = {1, 2, 3, 4};
    float s1 = product(v1);
    ensure(s1 == 24, "product test error 1");

    vector<float> v2 = {1, 2, 3, 4, 5, 6};
    float s2 = product(v2);
    ensure(s2 == 720, "product test error 2");
}

// ��ҵ 2
// ����һ�����ֵľ���ֵ
// ������������
//
// �ο����ſ������ֵ�Ĵ�����ʵ��
// 1. ��� n < 0���Ͱ� n ��ֵ��ֵ�� -n
// 2. ���� n ��ֵ������Ҫ��һ��Ҫ return n��
float abs1(float n)
{
    if (n < 0)
    {
        n = -n;
    }
    return n;
}

void testAbs(void)
{
    float v1 = 10;
    float s1 = abs1(v1);
    ensure(s1 == 10, "abs test error 1");

    float v2 = -12;
    float s2 = abs1(v2);
    ensure(s2 == 12, "abs test error 2");
}

// ��ҵ 3
// ������һ��ֻ�������ֵ�����
// �� ���� ���������ֵ�ƽ����
//
// ������������
// �������ƽ�������������������Ԫ�ص��ܺͣ�Ȼ���������ĳ��ȣ���Ԫ�صĸ�����
// 1. ʹ������ 1 �е� sum ��������������������Ԫ�ص��ܺ�
// 2. ʹ�� size ���������������Ԫ�صĸ���
// 3. ʹ��������Ԫ�ص��ܺͳ���������Ԫ�صĸ������õ�ƽ����
// 4. ����ƽ����
float average(vector<float> &array)
{
    float average = 0;
    for (int n = 0; n < array.size(); n++)
    {
        average += array[n];
    }
    average /= array.size();
    return average;
}

void testAverage(void)
{
    vector<float> v1 = {1, 2, 3, 4};
    float s1 = average(v1);
    ensure(s1 == 2.5, "average test error 1");

    vector<float> v2 = {1, 2, 3, 4, 5};
    float s2 = average(v2);
    ensure(s2 == 3, "average test error 2");
}

// ��ҵ 4
// ������һ��ֻ�������ֵ� ����
// �� ���� ����С������
//
// ��ѡ�����еĵ�һ��Ԫ����Ϊ s �ĳ�ʼֵ
// Ȼ��������飬��ÿһ��Ԫ�ض����ʼֵ�Ƚ�
// ���Ԫ�ص�ֵ�ȳ�ʼֵС���Ͱ��Ǹ�Ԫ������Ϊ s ��ֵ
// ��󷵻� s ��ֵ
// 1. �������е�һ��Ԫ�ص�ֵ��ֵ�� s ��Ϊ��ʼֵ
// 2. �������飬�ñ��� n ����Ԫ�ص�ֵ
// 3. �Ƚ� n �� s ��ֵ����� n < s���Ͱ� n ��ֵ��ֵ�� s
// 4. ѭ�������󣬱��� s ����������������С������
// 5. ���ر��� s������Ҫ��һ��Ҫ return s��
float min(vector<float> &array)
{
    int s = array[0];
    for (int n = 1; n < array.size(); n++)
    {
        if (s >= array[n])
        {
            s = array[n];
        }
    }
    return s;
}

void testMin(void)
{
    vector<float> v1 = {11, 20, 3, 45};
    float s1 = min(v1);
    ensure(s1 == 3, "min test error 1");

    vector<float> v2 = {11, 2, 1, 41, 3};
    float s2 = min(v2);
    ensure(s2 == 1, "min test error 2");
}

// ��ҵ 5
// ������һ������ n
// �����������еĽ��
// 1 - 2 + 3 - 4 + 5 ... n

// ���ȿ��԰����п�����һ�����飬�����Ϳ���ѭ�� n �Ρ�
// �۲����п��Է���һ�����ɣ�������ʱ���Ǽӣ�ż����ʱ���Ǽ�
//
// 1. ������һ������ s ���������еĺͣ���ʼֵΪ 0
// 2. ѭ�� n �Σ��� 1 ��ʼ���� n + 1 ������������ n ���ǲ����� n + 1
// 3. �ж�ÿ��ѭ����ֵ��������������ۼ�������� s �ϣ������ż�����ۼ�������� s ��
// 4. ѭ�������󣬱��� s �����������еĺ�
// 5. ���ر��� s������Ҫ��һ��Ҫ return s��
int sum1(int n)
{
    int s = 0;
    for (int i = 1; i < n + 1; i++)
    {
        if (i % 2 == 0)
        {
            s -= i;
        }
        else
        {
            s += i;
        }
    }
    return s;
}

void testSum1(void)
{
    int v1 = 5;
    int s1 = sum1(v1);
    ensure(s1 == 3, "sum1 test error 1");
    int v2 = 8;
    int s2 = sum1(v2);
    ensure(s2 == -4, "sum1 test error 2");
}
// ��ҵ 6
// ������һ������ n
// �����������еĽ��
// 1 + 2 - 3 + 4 - ... n
// ���ǰ����п�����һ�����飬�����ӵڶ���Ԫ�أ�Ҳ���� 2 ��ʼ�����������Ϳ���ѭ�� n - 1 ��
//
// 1. ������һ������ s ���������еĺͣ���ʼֵΪ 1�������Ϳ��Դ� 2 ��ʼ����ѭ����
// 2. ѭ�� n - 1 �Σ��� 2 ��ʼ���� n ���������� n��
// 3. �ж�ÿ��ѭ����ֵ��
//    ����ǵ�һ�����֣������Ǵ� 2 ��ʼ�ģ����۲�ʽ�ӵĹ��ɣ��� 2 ��ʼ֮�󣬵�һ������������ʱ�����Ǽ�ȥ�����������˵ 3 5 7 9...����
//    ��һ��������ż��ʱ�����Ǽ�������������� 2 4 6 8...����
// 4. ѭ�������󣬱��� s �����������еĺ�
// 5. ���ر��� s������Ҫ��һ��Ҫ return s��
int sum2(int n)
{
    int s = 1;
    for (int i = 2; i < n + 1; i++)
    {
        if (i % 2 == 0)
        {
            s += i;
        }
        else
        {
            s -= i;
        }
    }
    return s;
}

void testSum2(void)
{
    int v1 = 5;
    int s1 = sum2(v1);
    ensure(s1 == -1, "sum2 test error 1");
    int v2 = 8;
    int s2 = sum2(v2);
    ensure(s2 == 6, "sum2 test error 2");
}
// ��ҵ 7
//
// ʵ�� fac ����
// ����һ������ n
// ���� n �Ľ׳�, 1 * 2 * 3 * ... * n
// ����� 1 �� n �Ľ׳ˣ��ظ��� n �Σ����Կ�����ѭ��������
//
// 1. ������һ������ s ������׳ˣ���ʼֵΪ 1
// 2. ��ѭ���� 1 �� n ��������˱��浽 s ��
// 3. ѭ�������󣬱��� s �������Ǵ� 1 �� n �Ľ׳�, ���ر��� s������Ҫ��һ��Ҫ return s��
int fac(int n)
{
    int s = 1;
    for (int i = 1; i < n + 1; i++)
    {
        s *= i;
    }
    return s;
}

void testFac(void)
{
    int v1 = 5;
    int s1 = fac(v1);
    ensure(s1 == 120, "fac test error 1");
    int v2 = 8;
    int s2 = fac(v2);
    ensure(s2 == 40320, "fac test error 2");
}
//
void test()
{
    testSum2();
}

// main �����Ĳ����ǹ涨������ճ������
int main(int argc, const char *argv[])
{
    test();
    return 0;
}