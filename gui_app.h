#ifndef GUI_APP_H
#define GUI_APP_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QCheckBox>

class GuiApp : public QWidget
{
    Q_OBJECT  // Enables Qt's signal and slot mechanism

public:
    explicit GuiApp(QWidget *parent = nullptr);  // Constructor declaration

private slots:
    void onEncryptClicked();  // Slot for encrypt button
    void onDecryptClicked();  // Slot for decrypt button
    void toggleKeyVisibility(bool state);
    void toggleDarkMode(bool checked);


private:
    QLineEdit *keyInput;          // Input field for entering the key
    QPushButton *encryptButton;   // Button for encryption
    QPushButton *decryptButton;   // Button for decryption
    QCheckBox *showKeyCheckbox;
    QCheckBox *darkModeCheckbox;
    bool askForKey();             // Function to handle key input and set the round keys
    void encryptFile();           // Function to perform file encryption
    void decryptFile();           // Function to perform file decryption
};

#endif // GUI_APP_H
