#include "Component.hpp"
#include "EngineObject.hpp"
#include "Manager/MaterialManager.hpp"

Component::Component() { }

void Component::PreLoad() { }
void Component::Load() { loaded = true; }
void Component::PreRender() { }
void Component::Update() { }
void Component::Render() { }
void Component::PostRender() { }
void Component::Clean() { }