#include "MiniginPCH.h"
#include "Scene.h"
#include "GameObject.h"
#include <algorithm>

using namespace dae;

unsigned int Scene::m_IdCounter = 0;

Scene::Scene(const std::string& name) : m_Name(name) {}

void Scene::Add(const std::shared_ptr<SceneObject>& spObject)
{
	m_SpObjects.push_back(spObject);
}

void Scene::Update()
{
	for (const auto& object : m_SpObjects)
	{
		object->Update();
	}
}

void Scene::Render() const
{
	for (const auto& object : m_SpObjects)
	{
		object->Render();
	}
}

const std::string& Scene::GetName() const
{
	return m_Name;
}

std::shared_ptr<SceneObject> Scene::GetObjectByName(const std::string& name) const
{
	for (const auto& object : m_SpObjects)
	{
		if (object->GetName().compare(name) == 0)
		{
			return object;
		}
	}
	return nullptr;
}

void Scene::AddPlayer(const std::shared_ptr<GameObject>& spPlayer)
{
	m_SpPlayers.push_back(spPlayer);
}

std::shared_ptr<GameObject> Scene::GetPlayer(int index)
{
	if (m_SpPlayers.size() <= (unsigned)index)
	{
		return nullptr;
	}

	return m_SpPlayers[index];
}