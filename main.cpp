#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/terminal.hpp>

int main() {
    using namespace ftxui;

    auto element = text("Hello, FTXUI!") | border;
    auto document = vbox({element});
    auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
    Render(screen, document);
    screen.Print();
    return 0;
}