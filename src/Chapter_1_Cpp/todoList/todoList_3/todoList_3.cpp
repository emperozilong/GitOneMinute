#include <iostream>
#include "TodoManager.h"

int main() {
    try {
        TodoManager manager;
        manager.run();

        //TodoManager* pManager = new TodoManager();;
		//pManager->run();
    }
    catch (const std::exception& e) {
        std::cerr << "程序发生异常: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}