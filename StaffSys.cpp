#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <vector>
#include <cctype>
#include <map>
#include <stack>
using namespace std;

// 定义员工结构体，用于存储员工信息
struct Employee {
	char id[20]; // 员工工号
	char name[50]; // 员工姓名
	char position[50]; // 职位
	char department[50]; // 部门名称
	int salary; // 薪资
};

Employee employees[100]; // 员工数组，用于存储员工信息
int employeeCount = 0; // 员工数量

// 初始化示例员工数据
void initializeEmployees() {
	// 初始化示例员工，用于演示系统功能。
	Employee emp1 = {"EMP001", "张三", "开发工程师", "技术开发部", 8000};
	Employee emp2 = {"EMP002", "李四", "测试工程师", "测试部", 7500};
	Employee emp3 = {"EMP003", "王五", "项目经理", "项目管理部", 10000};
	Employee emp4 = {"EMP004", "王八", "项目经理", "测试部", 8000};
	employees[0] = emp1;
	employees[1] = emp2;
	employees[2] = emp3;
	employees[2] = emp4;
	employeeCount = 4;
}

// 显示所有员工信息
void viewAllEmployees() {
	cout << "当前系统中的员工信息如下：" << endl;
	for (int i = 0; i < employeeCount; i++) {
		cout << "员工ID: " << employees[i].id << endl;
		cout << "员工姓名: " << employees[i].name << endl;
		cout << "职位: " << employees[i].position << endl;
		cout << "部门名称: " << employees[i].department << endl;
		cout << "薪资: " << employees[i].salary << endl;
		cout << "-------------------" << endl;
	}
}

// 添加员工信息
void addEmployee() {
	Employee newEmployee;

	cout << "请输入新员工的工号: ";
	cin >> newEmployee.id;
	// 检查工号是否重复
	for (int i = 0; i < employeeCount; i++) {
		if (strcmp(employees[i].id, newEmployee.id) == 0) {
			cout << "该工号已存在，请重新输入。" << endl;
			return;
		}
	}
	cout << "请输入新员工的姓名: ";
	cin >> newEmployee.name;
	cout << "请输入新员工的职位: ";
	cin >> newEmployee.position;
	cout << "请输入新员工的部门名称: ";
	cin >> newEmployee.department;
	cout << "请输入新员工的薪资: ";
	cin >> newEmployee.salary;

	employees[employeeCount] = newEmployee;
	employeeCount++;
	cout << "新员工已成功添加。" << endl;
}

// 按工号查询员工信息
void searchById() {
	char searchId[20];
	cout << "请输入要查询的员工工号: ";
	cin >> searchId;
	bool found = false;
	for (int i = 0; i < employeeCount; i++) {
		if (strcmp(employees[i].id, searchId) == 0) {
			cout << "员工信息如下：" << endl;
			cout << "员工ID: " << employees[i].id << endl;
			cout << "员工姓名: " << employees[i].name << endl;
			cout << "职位: " << employees[i].position << endl;
			cout << "部门名称: " << employees[i].department << endl;
			cout << "薪资: " << employees[i].salary << endl;
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "未找到该工号的员工。" << endl;
	}
}

// 按姓名查询员工信息
void searchByName() {
	char searchName[50];
	cout << "请输入要查询的员工姓名: ";
	cin >> searchName;
	bool found = false;
	for (int i = 0; i < employeeCount; i++) {
		if (strcmp(employees[i].name, searchName) == 0) {
			cout << "员工信息如下：" << endl;
			cout << "员工ID: " << employees[i].id << endl;
			cout << "员工姓名: " << employees[i].name << endl;
			cout << "职位: " << employees[i].position << endl;
			cout << "部门名称: " << employees[i].department << endl;
			cout << "薪资: " << employees[i].salary << endl;
			cout << "-------------------" << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "未找到该姓名的员工。" << endl;
	}
}

// 按职位查询员工信息
void searchByPosition() {
	char searchPosition[50];
	cout << "请输入要查询的职位: ";
	cin >> searchPosition;
	bool found = false;
	for (int i = 0; i < employeeCount; i++) {
		if (strcmp(employees[i].position, searchPosition) == 0) {
			cout << "员工信息如下：" << endl;
			cout << "员工ID: " << employees[i].id << endl;
			cout << "员工姓名: " << employees[i].name << endl;
			cout << "职位: " << employees[i].position << endl;
			cout << "部门名称: " << employees[i].department << endl;
			cout << "薪资: " << employees[i].salary << endl;
			cout << "-------------------" << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "未找到该职位的员工。" << endl;
	}
}

// 按部门查询员工信息
void searchByDepartment() {
	char searchDepartment[50];
	cout << "请输入要查询的部门名称: ";
	cin >> searchDepartment;
	bool found = false;
	for (int i = 0; i < employeeCount; i++) {
		if (strcmp(employees[i].department, searchDepartment) == 0) {
			cout << "员工信息如下：" << endl;
			cout << "员工ID: " << employees[i].id << endl;
			cout << "员工姓名: " << employees[i].name << endl;
			cout << "职位: " << employees[i].position << endl;
			cout << "部门名称: " << employees[i].department << endl;
			cout << "薪资: " << employees[i].salary << endl;
			cout << "-------------------" << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "未找到该部门的员工。" << endl;
	}
}

// 删除员工信息（按工号）
void deleteEmployeeById() {
	char idToDelete[20];
	cout << "请输入要删除的员工工号: ";
	cin >> idToDelete;
	bool found = false;
	for (int i = 0; i < employeeCount; i++) {
		if (strcmp(employees[i].id, idToDelete) == 0) {
			// 删除员工信息，将数组中的元素向前移动
			for (int j = i; j < employeeCount - 1; j++) {
				employees[j] = employees[j + 1];
			}
			employeeCount--;
			found = true;
			cout << "员工信息已成功删除。" << endl;
			break;
		}
	}
	if (!found) {
		cout << "未找到该工号的员工。" << endl;
	}
}

// 辅助函数：显示员工信息
void displayEmployee(const Employee& emp) {
    cout << "员工ID: " << emp.id << endl;
    cout << "员工姓名: " << emp.name << endl;
    cout << "职位: " << emp.position << endl;
    cout << "部门名称: " << emp.department << endl;
    cout << "薪资: " << emp.salary << endl;
    cout << "-------------------" << endl;
}

// 改进后的查询函数，返回匹配的员工索引列表
vector<int> searchEmployees(int searchType) {
    vector<int> matches;
    char searchTerm[50];
    
    switch(searchType) {
        case 1: // 按工号查询
            cout << "请输入要查询的员工工号: ";
            cin >> searchTerm;
            for (int i = 0; i < employeeCount; i++) {
                if (strcmp(employees[i].id, searchTerm) == 0) {
                    matches.push_back(i);
                }
            }
            break;
        case 2: // 按姓名查询
            cout << "请输入要查询的员工姓名: ";
            cin >> searchTerm;
            for (int i = 0; i < employeeCount; i++) {
                if (strcmp(employees[i].name, searchTerm) == 0) {
                    matches.push_back(i);
                }
            }
            break;
        case 3: // 按职位查询
            cout << "请输入要查询的职位: ";
            cin >> searchTerm;
            for (int i = 0; i < employeeCount; i++) {
                if (strcmp(employees[i].position, searchTerm) == 0) {
                    matches.push_back(i);
                }
            }
            break;
        case 4: // 按部门查询
            cout << "请输入要查询的部门: ";
            cin >> searchTerm;
            for (int i = 0; i < employeeCount; i++) {
                if (strcmp(employees[i].department, searchTerm) == 0) {
                    matches.push_back(i);
                }
            }
            break;
    }
    
    return matches;
}

// 修改员工信息 
void modifyEmployee() {
    while (true) {
        cout << "\n欢迎使用员工信息修改系统" << endl;
        cout << "1. 按工号查询员工信息" << endl;
        cout << "2. 按姓名查询员工信息" << endl;
        cout << "3. 按职位查询员工信息" << endl;
        cout << "4. 按部门查询员工信息" << endl;
        cout << "5. 返回主菜单" << endl;
        cout << "请输入您的选择 (1-5): ";
        
        int choice;
        cin >> choice;
        
        if (choice == 5) return;
        if (choice < 1 || choice > 4) {
            cout << "无效的选择，请重新输入。" << endl;
            continue;
        }
        
        // 查询员工
        vector<int> matches = searchEmployees(choice);
        
        if (matches.empty()) {
            cout << "未找到匹配的员工。" << endl;
            continue;
        }
        
        // 显示查询结果
        cout << "\n找到 " << matches.size() << " 位匹配的员工:" << endl;
        for (int i = 0; i < matches.size(); i++) {
            cout << "[" << i+1 << "] ";
            displayEmployee(employees[matches[i]]);
        }
        
        // 处理多个匹配的情况
        int selectedIndex = 0;
        if (matches.size() > 1) {
            cout << "请输入要修改的员工编号(1-" << matches.size() << "): ";
            cin >> selectedIndex;
            if (selectedIndex < 1 || selectedIndex > matches.size()) {
                cout << "无效的编号。" << endl;
                continue;
            }
            selectedIndex--; // 转换为0-based索引
        }
        
        Employee& emp = employees[matches[selectedIndex]];
        
        // 修改员工信息
        while (true) {
            cout << "\n当前员工信息:" << endl;
            displayEmployee(emp);
            
            cout << "请选择要修改的信息:" << endl;
            cout << "1. 工号" << endl;
            cout << "2. 姓名" << endl;
            cout << "3. 职位" << endl;
            cout << "4. 部门" << endl;
            cout << "5. 薪资" << endl;
            cout << "6. 返回上级" << endl;
            cout << "请输入您的选择 (1-6): ";
            
            int fieldChoice;
            cin >> fieldChoice;
            
            if (fieldChoice == 6) break;
            
            char confirm;
            switch(fieldChoice) {
                case 1: // 修改工号
                    cout << "当前工号: " << emp.id << endl;
                    cout << "请输入新工号: ";
                    char newId[20];
                    cin >> newId;
                    cout << "确认将工号从 " << emp.id << " 修改为 " << newId << " 吗?(Y/N): ";
                    cin >> confirm;
                    if (confirm == 'Y' || confirm == 'y') {
                        strcpy(emp.id, newId);
                        cout << "工号已修改。" << endl;
                    }
                    break;
                case 2: // 修改姓名
                    cout << "当前姓名: " << emp.name << endl;
                    cout << "请输入新姓名: ";
                    char newName[50];
                    cin >> newName;
                    cout << "确认将姓名从 " << emp.name << " 修改为 " << newName << " 吗?(Y/N): ";
                    cin >> confirm;
                    if (confirm == 'Y' || confirm == 'y') {
                        strcpy(emp.name, newName);
                        cout << "姓名已修改。" << endl;
                    }
                    break;
                case 3: // 修改职位
                    cout << "当前职位: " << emp.position << endl;
                    cout << "请输入新职位: ";
                    char newPosition[50];
                    cin >> newPosition;
                    cout << "确认将职位从 " << emp.position << " 修改为 " << newPosition << " 吗?(Y/N): ";
                    cin >> confirm;
                    if (confirm == 'Y' || confirm == 'y') {
                        strcpy(emp.position, newPosition);
                        cout << "职位已修改。" << endl;
                    }
                    break;
                case 4: // 修改部门
                    cout << "当前部门: " << emp.department << endl;
                    cout << "请输入新部门: ";
                    char newDepartment[50];
                    cin >> newDepartment;
                    cout << "确认将部门从 " << emp.department << " 修改为 " << newDepartment << " 吗?(Y/N): ";
                    cin >> confirm;
                    if (confirm == 'Y' || confirm == 'y') {
                        strcpy(emp.department, newDepartment);
                        cout << "部门已修改。" << endl;
                    }
                    break;
                case 5: // 修改薪资
                    cout << "当前薪资: " << emp.salary << endl;
                    cout << "请输入新薪资: ";
                    int newSalary;
                    cin >> newSalary;
                    cout << "确认将薪资从 " << emp.salary << " 修改为 " << newSalary << " 吗?(Y/N): ";
                    cin >> confirm;
                    if (confirm == 'Y' || confirm == 'y') {
                        emp.salary = newSalary;
                        cout << "薪资已修改。" << endl;
                    }
                    break;
                default:
                    cout << "无效的选择，请重新输入。" << endl;
            }
            
            cout << "是否继续修改此员工的其他信息?(Y/N): ";
            cin >> confirm;
            if (confirm != 'Y' && confirm != 'y') break;
        }
        
        cout << "是否继续修改其他员工?(Y/N): ";
        char continueChoice;
        cin >> continueChoice;
        if (continueChoice != 'Y' && continueChoice != 'y') break;
    }
}


// 显示主菜单
void showMainMenu() {
	int choice;
	do {
		cout << "欢迎使用员工管理系统" << endl;
		cout << "1. 添加员工信息" << endl;
		cout << "2. 按工号查询员工信息" << endl;
		cout << "3. 按姓名查询员工信息" << endl;
		cout << "4. 按职位查询员工信息" << endl;
		cout << "5. 按部门查询员工信息" << endl;
		cout << "6. 显示所有员工信息" << endl;
		cout << "7. 删除员工信息" << endl;
		cout << "8. 修改员工信息" << endl;
		cout << "9. 退出系统" << endl;

		cout << "请输入您的选择 (1-9): ";
		cin >> choice;

		switch (choice) {
			case 1:
				addEmployee();
				break;
			case 2:
				searchById();
				break;
			case 3:
				searchByName();
				break;
			case 4:
				searchByPosition();
				break;
			case 5:
				searchByDepartment();
				break;
			case 6:
				viewAllEmployees();
				break;
			case 7:
				deleteEmployeeById();
				break;
			case 8:
				modifyEmployee();
				break;
			case 9:
				cout << "感谢使用员工管理系统，再见！" << endl;
				break;
			default:
				cout << "无效的选择，请重新输入。" << endl;
		}
	} while (choice != 9);
}

// 按工号排序员工信息
void sortByEmployeeId(Employee employees[], int size, bool ascending = true) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (ascending) {
				if (strcmp(employees[j].id, employees[j + 1].id) > 0) {
					swap(employees[j], employees[j + 1]);
				}
			} else {
				if (strcmp(employees[j].id, employees[j + 1].id) < 0) {
					swap(employees[j], employees[j + 1]);
				}
			}
		}
	}
}

// 按姓名排序员工信息
void sortByName(Employee employees[], int size, bool ascending = true) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (ascending) {
				if (strcmp(employees[j].name, employees[j + 1].name) > 0) {
					swap(employees[j], employees[j + 1]);
				}
			} else {
				if (strcmp(employees[j].name, employees[j + 1].name) < 0) {
					swap(employees[j], employees[j + 1]);
				}
			}
		}
	}
}

// 按薪资排序员工信息
void sortBySalary(Employee employees[], int size, bool ascending = true) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (ascending) {
				if (employees[j].salary > employees[j + 1].salary) {
					swap(employees[j], employees[j + 1]);
				}
			} else {
				if (employees[j].salary < employees[j + 1].salary) {
					swap(employees[j], employees[j + 1]);
				}
			}
		}
	}
}

// 排序工具函数
void sortEmployees() {
	int choice;
	int sortOrderChoice;

	cout << "请选择排序方式：" << endl;
	cout << "1. 按工号排序" << endl;
	cout << "2. 按姓名排序" << endl;
	cout << "3. 按薪资排序" << endl;
	cout << "请输入您的选择 (1-3): ";
	cin >> choice;

	cout << "请选择排序顺序：" << endl;
	cout << "1. 升序排列" << endl;
	cout << "2. 降序排列" << endl;
	cout << "请输入您的选择 (1-2): ";
	cin >> sortOrderChoice;

	bool ascending = (sortOrderChoice == 1);

	switch (choice) {
		case 1:
			sortByEmployeeId(employees, employeeCount, ascending);
			break;
		case 2:
			sortByName(employees, employeeCount, ascending);
			break;
		case 3:
			sortBySalary(employees, employeeCount, ascending);
			break;
		default:
			cout << "无效的选择，请重新输入。" << endl;
			return;
	}
	cout << "排序完成。" << endl;
}

// 测试排序功能
void testSortFunctions() {
	// 初始化示例员工信息用于测试排序
	Employee emp4 = {"EMP004", "赵六", "高级开发工程师", "技术开发部", 9500};
	Employee emp5 = {"EMP005", "钱七", "初级开发工程师", "技术开发部", 6000};
	employees[3] = emp4;
	employees[4] = emp5;
	employeeCount = 5;
}

// 定义用户角色和登录信息
struct User {
    string username;
    string password;
    string role; // "admin" 或 "user"
};

// 预定义用户
User validUsers[2] = {
    {"admin", "admin123", "admin"},
    {"user", "user123", "user"}
};



// 登录验证函数
bool login(string& currentRole) {
    string username, password;
    int attempts = 0;
    
    while (attempts < 3) {
        cout << "========== 员工管理系统登录 ==========" << endl;
        cout << "用户名: ";
        cin >> username;
        cout << "密码: ";
        cin >> password;
        
        for (const auto& user : validUsers) {
            if (user.username == username && user.password == password) {
                currentRole = user.role;
                cout << "登录成功！欢迎, " << username << " (" << user.role << ")" << endl;
                return true;
            }
        }
        
        attempts++;
        cout << "用户名或密码错误，还剩 " << 3 - attempts << " 次尝试机会。" << endl;
    }
    
    cout << "登录失败次数过多，系统将退出。" << endl;
    return false;
}

// 显示用户菜单
void showUserMenu(const string& role) {
    cout << "\n========== 员工管理系统 ==========" << endl;
    cout << "1. 按工号查询员工信息" << endl;
    cout << "2. 按姓名查询员工信息" << endl;
    cout << "3. 按职位查询员工信息" << endl;
    cout << "4. 按部门查询员工信息" << endl;
    cout << "5. 显示所有员工信息" << endl;
    
    if (role == "admin") {
        cout << "6. 添加员工信息" << endl;
        cout << "7. 删除员工信息" << endl;
        cout << "8. 修改员工信息" << endl;
        cout << "9. 排序员工信息" << endl;
        cout << "10. 退出系统" << endl;
        cout << "请输入您的选择 (1-10): ";
    } else {
        cout << "6. 退出系统" << endl;
        cout << "请输入您的选择 (1-6): ";
    }
}


// 主系统循环
void runSystem(const string& role) {
    int choice;
    bool running = true;
    
    while (running) {
        showUserMenu(role);
        cin >> choice;
        
        // 清除输入缓冲区
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        // 根据用户角色处理不同选项
        if (role == "admin") {
            switch (choice) {
                case 1: searchById(); break;
                case 2: searchByName(); break;
                case 3: searchByPosition(); break;
                case 4: searchByDepartment(); break;
                case 5: viewAllEmployees(); break;
                case 6: addEmployee(); break;
                case 7: deleteEmployeeById(); break;
                case 8: modifyEmployee(); break;
                case 9: sortEmployees(); break;
                case 10: running = false; break;
                default: cout << "无效的选择，请重新输入。" << endl;
            }
        } else {
            switch (choice) {
                case 1: searchById(); break;
                case 2: searchByName(); break;
                case 3: searchByPosition(); break;
                case 4: searchByDepartment(); break;
                case 5: viewAllEmployees(); break;
                case 6: running = false; break;
                default: cout << "无效的选择，请重新输入。" << endl;
            }
        }
        
        if (running) {
            cout << "\n按回车键继续...";
            cin.get();
        }
    }
    
    cout << "感谢使用员工管理系统，再见！" << endl;
}

int main() {
    string currentRole;
    
    // 登录验证
    if (!login(currentRole)) {
        return 0;
    }
    
    // 初始化员工数据
    initializeEmployees();
    
    // 运行主系统
    runSystem(currentRole);
    
    return 0;
}
