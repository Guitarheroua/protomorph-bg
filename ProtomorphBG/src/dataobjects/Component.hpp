#ifndef COMPONENTOBJECT_HPP
#define COMPONENTOBJECT_HPP

#include "src/constants/Enums.hpp"
#include "src/dataobjects/Background.hpp"
#include "src/dataobjects/Borders.hpp"
#include "src/dataobjects/ComponentDecoration.hpp"

#include <QSizeF>

#include <vector>

namespace Dataobject {
struct Component
{
    std::vector<ComponentDecoration *> componentDecorations;
    Backround background;
    Borders borders;
    QSizeF size;
    Enums::ComponentType type;
};
}
#endif // COMPONENTOBJECT_HPP
