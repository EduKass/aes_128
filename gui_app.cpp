#include "gui_app.h"
#include "aes.h" // Include your header file
#include <QVBoxLayout>
#include <QMessageBox>
#include <QFileDialog>
#include <fstream>
#include <QStyle>
#include <QLabel>
#include <QCheckBox>
#include <QIcon>
using namespace std;

GuiApp::GuiApp(QWidget *parent) : QWidget(parent) {
    setWindowTitle("AES Encryption/Decryption");
    setWindowIcon(QIcon("icon.ico"));
    setFixedSize(400, 300);

    QVBoxLayout *layout = new QVBoxLayout();

    // Key input
    QLabel *keyLabel = new QLabel("Enter Encryption Key:");
    keyLabel->setStyleSheet("font-size: 16px; font-weight: bold; margin-bottom: 5px;");
    layout->addWidget(keyLabel);
    keyInput = new QLineEdit();
    keyInput->setPlaceholderText("Enter your key here");
    keyInput->setEchoMode(QLineEdit::Password);
    keyInput->setStyleSheet("border: 2px solid #4CAF50; border-radius: 5px; padding: 5px; font-size: 14px;");
    layout->addWidget(keyInput);

    // Key checkbox
    QHBoxLayout *checkboxLayout = new QHBoxLayout();
    showKeyCheckbox = new QCheckBox("Show Key");
    checkboxLayout->addWidget(showKeyCheckbox);
    layout->addLayout(checkboxLayout);

    connect(showKeyCheckbox, &QCheckBox::toggled, this, &GuiApp::toggleKeyVisibility);

    // Encrypt and Decrypt buttons
    encryptButton = new QPushButton("Encrypt File");
    encryptButton->setStyleSheet("background-color: #4CAF50; color: white; padding: 10px; border-radius: 5px;");
    layout->addWidget(encryptButton);
    decryptButton = new QPushButton("Decrypt File");
    decryptButton->setStyleSheet("background-color: #4CAF50; color: white; padding: 10px; border-radius: 5px;");
    layout->addWidget(decryptButton);

    // Dark mode checkbox
    darkModeCheckbox = new QCheckBox("Enable Dark Mode");
    layout->addWidget(darkModeCheckbox);
    connect(darkModeCheckbox, &QCheckBox::toggled, this, &GuiApp::toggleDarkMode);

    setLayout(layout);
    connect(encryptButton, &QPushButton::clicked, this, &GuiApp::onEncryptClicked);
    connect(decryptButton, &QPushButton::clicked, this, &GuiApp::onDecryptClicked);
}

void GuiApp::onEncryptClicked() {
    if (!askForKey()) {
        return; // Stop the function if key size is invalid
    }
    encryptFile();
    keyInput->clear();  // Clear the input field after encryption
}

void GuiApp::onDecryptClicked() {
    if (!askForKey()) {
        return; // Stop the function if key size is invalid
    }
    decryptFile();
    keyInput->clear();  // Clear the input field after decryption
}

void GuiApp::toggleKeyVisibility(bool checked) {
    if (checked) {
        keyInput->setEchoMode(QLineEdit::Normal); // Show key
    } else {
        keyInput->setEchoMode(QLineEdit::Password); // Hide key
    }
}

void GuiApp::toggleDarkMode(bool checked) {
    if (checked) {
        // Dark mode styles
        setStyleSheet(
            "QWidget { background-color: #2e2e2e; color: white; }"
            "QPushButton { background-color: #555555; color: white; padding: 10px; border-radius: 5px; font-size: 14px; }"
            "QLineEdit { background-color: #444444; color: white; border: 2px solid #888888; border-radius: 5px; padding: 5px; font-size: 14px; }"
            "QLabel { color: white; font-size: 16px; font-weight: bold; }"
            "QCheckBox { color: white; font-size: 14px; }"
            );
    } else {
        // Light mode styles
        setStyleSheet(
            "QWidget { background-color: #f0f0f0; color: black; }"
            "QPushButton { background-color: #4CAF50; color: white; padding: 10px; border-radius: 5px; font-size: 14px; }"
            "QLineEdit { background-color: white; color: black; border: 2px solid #4CAF50; border-radius: 5px; padding: 5px; font-size: 14px; }"
            "QLabel { color: black; font-size: 16px; font-weight: bold; }"
            "QCheckBox { color: black; font-size: 14px; }"
            );
    }
}

bool GuiApp::askForKey() {
    QString keyText = keyInput->text();
    QByteArray keyArray = keyText.toUtf8();

    if (keyArray.size() < KEY_SIZE) {
        QMessageBox::warning(this, "Error", "Key must be at least " + QString::number(KEY_SIZE) + " characters long.");
        return false;
    }

    // Manually copy the key bytes to the key array
    for (int i = 0; i < KEY_SIZE; ++i) {
        if (i < keyArray.size()) {
            key[i] = keyArray[i];  // Copy byte by byte
        } else {
            key[i] = 0;  // Fill with zero if key is shorter than KEY_SIZE
        }
    }

    generateRoundKeys(key);
    return true;
}

void GuiApp::encryptFile() {
    QString filePath = QFileDialog::getOpenFileName(this, "Select a File to Encrypt");
    if (filePath.isEmpty()) {
        QMessageBox::warning(this, "Error", "No file selected for encryption.");
        return;
    }

    fstream file(filePath.toStdString(), ios::in | ios::out | ios::binary);
    if (!file.is_open()) {
        QMessageBox::warning(this, "Error", "Failed to open file for encryption.");
        return;
    }

    file.seekg(0, ios::end);
    int fileSize = file.tellg();
    file.seekg(0, ios::beg);

    unsigned char* fileBuffer = new unsigned char[fileSize];
    file.read(reinterpret_cast<char*>(fileBuffer), fileSize);

    addPadding(fileBuffer, fileSize);

    unsigned char* encryptedFileBuffer = new unsigned char[fileSize];

    cbcEncrypt(fileBuffer, encryptedFileBuffer, fileSize, iv);

    file.seekp(0, std::ios::beg);
    file.write(reinterpret_cast<char*>(encryptedFileBuffer), fileSize);
    file.close();

    delete[] fileBuffer;
    delete[] encryptedFileBuffer;

    QMessageBox::information(this, "Success", "File encrypted successfully.");
}

void GuiApp::decryptFile() {
    QString filePath = QFileDialog::getOpenFileName(this, "Select a File to Decrypt");
    if (filePath.isEmpty()) {
        QMessageBox::warning(this, "Error", "No file selected for decryption.");
        return;
    }

    fstream file(filePath.toStdString(), ios::in | ios::out | ios::binary);
    if (!file.is_open()) {
        QMessageBox::warning(this, "Error", "Failed to open file for decryption.");
        return;
    }

    file.seekg(0, ios::end);
    int fileSize = file.tellg();
    file.seekg(0, ios::beg);

    unsigned char* fileBuffer = new unsigned char[fileSize];
    file.read(reinterpret_cast<char*>(fileBuffer), fileSize);

    unsigned char* decryptedFileBuffer = new unsigned char[fileSize];

    cbcDecrypt(fileBuffer, decryptedFileBuffer, fileSize, iv);

    file.seekp(0, ios::beg);
    file.write(reinterpret_cast<char*>(decryptedFileBuffer), fileSize);

    char c;
    for (int i = fileSize; i > fileSize - 16 && i > 0; i--) {
        file.seekg(i - 1); // Move the read pointer
        file.get(c);       // Read the character

        if (c == '0') {
            file.seekp(i - 1); // Move the write pointer back to the same position
            file.write(" ", 1);
        } else {
            break; // Stop when a non-'0' character is encountered
        }
    }
    file.close();

    delete[] fileBuffer;
    delete[] decryptedFileBuffer;

    QMessageBox::information(this, "Success", "File decrypted successfully.");
}
