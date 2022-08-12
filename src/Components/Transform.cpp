#include "Transform.hpp"
#include "Multithread/EngineObject.hpp"

Transform::Transform(EngineObject* _object) {
    object = _object;
    position = Vector3::Zero();
    scale = Vector3::One();
    rotation = Quaternion();
    UpdateTransform();
}

void Transform::UpdateTransform() {
    transform = Matrix4::Scale(scale) * Matrix4::Translate(position) * Matrix4::FromQuaternion(rotation);
}
