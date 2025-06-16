#include <iostream>
#include <vector>
#include <string>
#include <array>

#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/terminal.hpp>

using namespace ftxui;

int main() {
    std::vector<std::string> tasks;
    std::vector<char> states;

    std::string new_task;

    InputOption input_opt = InputOption::Default();

    auto checkbox_container = Container::Vertical({});
    auto input_container = Container::Vertical({});

    input_opt.on_enter = [&] {
        if (!new_task.empty()){
            tasks.push_back(new_task);
            states.push_back(0);

            bool* flag = reinterpret_cast<bool*>(&states.back());

            checkbox_container->Add(
                Checkbox(new_task, flag)
            );
            new_task.clear();
        }
    };

    auto input = Input(&new_task, "Add a task...", input_opt);
    input_container->Add(input);

    auto main_container = Container::Vertical({
        checkbox_container,
        input_container
    });

    auto renderer = Renderer(main_container, [&] {
        return main_container->Render()
                | vscroll_indicator
                | frame
                | size(HEIGHT, LESS_THAN, 10)
                | border;   
    });

    auto screen = ScreenInteractive::FitComponent();
    screen.Loop(renderer);

    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << (states[i] ? "[x] " : "[ ] ")
                << tasks[i] << "\n";
    }

    return 0;
}