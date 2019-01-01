pragma Singleton
import QtQuick 2.12
import QuickFlux 1.0

ActionCreator {
    //Application actions
    signal startApp
    signal quitApp

    //Component edit screen actions
    signal changeComponentHeight(int height);
    signal changeComponentWidth(int width);
}