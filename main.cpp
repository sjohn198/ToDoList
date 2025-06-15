#include <iostream>
#include <array>
#include <string>

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
    /*CHECKBOX EXAMPLE*/
    // bool task_completed = false;
    
    // auto container = Container::Vertical({
    //     Checkbox("Completed?", &task_completed)
    // });

    // auto screen = ScreenInteractive::FitComponent(); //ignore this red line
    // screen.Loop(container);
    // //Render(screen, document);
    // //screen.Print();

    // std::cout << "---" << std::endl;
    // std::cout << "Completed? " << task_completed << std::endl;
    // std::cout << "---" << std::endl;

    /*CHECKBOX_IN_FRAME EXAMPLE*/
    std::array<bool, 30> states;

    auto container = Container::Vertical({});
    for (int i = 0; i < 30; i++) {
        states[i] = false;
        container->Add(Checkbox("Checkbox #" + std::to_string(i), &states[i]));
    }

    auto renderer = Renderer(container, [&] {
        return container->Render() | vscroll_indicator | frame | size(HEIGHT, LESS_THAN, 10) | border;
    });

    auto screen = ScreenInteractive::FitComponent();
    screen.Loop(renderer);
    return 0;
}