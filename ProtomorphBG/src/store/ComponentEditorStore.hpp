#ifndef COMPONENTEDITORSTORE_HPP
#define COMPONENTEDITORSTORE_HPP

#include "src/constants/Enums.hpp"

#include <qfstore.h>

#include <QColor>

#include <memory>
#include <vector>

namespace Dataobject {
struct EditorComponent;
}

class DecorationStore;
class DecorationProducer;

class ComponentEditorStore: public QFStore
{
    Q_OBJECT
    Q_PROPERTY(double height READ height NOTIFY heightChanged)
    Q_PROPERTY(double width READ width NOTIFY widthChanged)
    Q_PROPERTY(double borderWidth READ borderWidth NOTIFY borderWidthChanged)
    Q_PROPERTY(QColor borderColor READ borderColor NOTIFY borderColorChanged)
    Q_PROPERTY(Enums::BackgroundType backgroundType READ backgroundType NOTIFY backgroundTypeChanged)
    Q_PROPERTY(QVariant backgroundValue READ backgroundValue NOTIFY backgroundValueChanged)
    Q_PROPERTY(Enums::ComponentType componentType READ componentType WRITE setComponentType NOTIFY componentTypeChanged)

    enum class SupportedAction
    {
        ADD_DECORATION,
        CHANGE_COMPONENT_BACKGROUND,
        CHANGE_COMPONENT_BORDERS,
        CHANGE_COMPONENT_SIZE
    };

public:
    static ComponentEditorStore *instance();
    void setComponent(std::shared_ptr<Dataobject::EditorComponent> &component);

    double width() const;
    double height() const;
    double borderWidth() const;
    QColor borderColor() const;
    Enums::BackgroundType backgroundType() const;
    QVariant backgroundValue() const;
    Enums::ComponentType componentType() const;

signals:
    void widthChanged(double width);
    void heightChanged(double height);
    void borderWidthChanged(double borderWidth);
    void borderColorChanged(QColor borderColor);
    void backgroundTypeChanged(Enums::BackgroundType backgroundType);
    void backgroundValueChanged(QVariant backgroundValue);
    void componentTypeChanged(Enums::ComponentType componentType);

private slots:
    void onDispatched(const QString &type, const QJSValue &message);

private:
    explicit ComponentEditorStore(QObject *parent = nullptr);
    virtual ~ComponentEditorStore() override;

    void setBackground(const QVariantMap &backgroundProp);
    void setBorders(const QVariantMap &bordersProp);
    void setComponentType(Enums::ComponentType componentType);
    void setComponentSize(QSizeF componentSize);

    std::vector<std::unique_ptr<DecorationStore>> m_decorationStores;
    QMap<QString, ComponentEditorStore::SupportedAction> m_supportedActionsMap;
    std::shared_ptr<Dataobject::EditorComponent> m_component;
    std::unique_ptr<DecorationProducer> m_decorationProducer;
};

#endif // COMPONENTEDITORSTORE_HPP
