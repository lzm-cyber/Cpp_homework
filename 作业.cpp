#include <iostream>
#include <string>
using namespace std;

// 定义student类
class student {
private:
    string id;     // 学号
    string name;   // 姓名
    int age;       // 年龄
    string major;  // 专业
public:
    // 有参构造函数（类内声明，类外实现）
    student(string i, string n, int a, string m);
    // 析构函数
    ~student();
    // 获取私有属性的info函数
    void info() const;
    // 修改私有属性的set函数（每个属性对应一个set）
    void setId(string i) { id = i; }
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setMajor(string m) { major = m; }
};

// 有参构造函数的类外实现
student::student(string i, string n, int a, string m) 
    : id(i), name(n), age(a), major(m) {
    cout << "student对象已创建" << endl;
}

// 析构函数的类外实现
student::~student() {
    cout << "student对象" << name << "已销毁" << endl;
}

// info函数的类外实现
void student::info() const {
    cout << "学号：" << id << endl;
    cout << "姓名：" << name << endl;
    cout << "年龄：" << age << endl;
    cout << "专业：" << major << endl;
}


// 定义graduate类（继承student）
class graduate : public student {
private:
    string gradTime;  // 本科毕业时间
    string tutor;     // 导师
public:
    // 有参构造函数（调用父类构造函数）
    graduate(string i, string n, int a, string m, string gt, string t)
        : student(i, n, a, m), gradTime(gt), tutor(t) {
        cout << "graduate对象已创建" << endl;
    }
    // 析构函数
    ~graduate() {
        cout << "graduate对象已销毁" << endl;
    }
    // 重写info函数（包含新增属性）
    void info() const {
        student::info();  // 调用父类的info
        cout << "本科毕业时间：" << gradTime << endl;
        cout << "导师：" << tutor << endl;
    }
    // 修改新增属性的set函数
    void setGradTime(string gt) { gradTime = gt; }
    void setTutor(string t) { tutor = t; }
};


// main函数
int main() {
    // 实例化2个student对象
    student s1("2023001", "张三", 18, "计算机科学");
    student s2("2023002", "李四", 19, "电子信息");

    // 实例化1个graduate对象
    graduate g1("2023003", "王五", 22, "软件工程", "2023-06", "赵教授");

    cout << "\n--- 修改前信息 ---" << endl;
    s1.info();
    cout << "-------------------" << endl;
    s2.info();
    cout << "-------------------" << endl;
    g1.info();

    // 调用set函数修改属性
    s1.setAge(19);
    s2.setMajor("通信工程");
    g1.setTutor("钱教授");

    cout << "\n--- 修改后信息 ---" << endl;
    s1.info();
    cout << "-------------------" << endl;
    s2.info();
    cout << "-------------------" << endl;
    g1.info();

    return 0;
}
