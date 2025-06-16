#include "disk_operations.h"

void load_from_disk(std::vector<std::string>& tasks, 
                    std::vector<char>& states, 
                    const std::string& filename) {
    std::ifstream in(filename);

    if (!in) return;

    std::string line;
    while(std::getline(in, line)) {
        std::istringstream parser(line);
        int flag;
        std::string task;

        if (parser >> flag) {
            if (parser.peek() == '\t') parser.get();
            std::getline(parser, task);

            states.push_back(flag);
            tasks.push_back(std::move(task));
        }
    }
}

void save_to_disk(const std::vector<std::string>& tasks,
                  const std::vector<char>& states,
                  const std::string& filename) {
    std::ofstream out(filename, std::ios::trunc);

    for(int i = 0; i < tasks.size(); i++) {
        std::cout << "Saving item: " << states[i] << '\t' << tasks[i] << '\n' << std::endl;
        out << (states[i] ? '1' : '0')
            << '\t'
            << tasks[i]
            << '\n';
    }
}