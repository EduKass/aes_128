#include <QApplication>
#include "gui_app.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create an instance of the main application window
    GuiApp mainWindow;
    mainWindow.show(); // Show the main window

    // Run the application event loop
    return app.exec();
}
