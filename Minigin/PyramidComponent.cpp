#pragma once
#include "MiniginPCH.h"
#include "PyramidComponent.h"
#include "Renderer.h"
#include "TransformComponent.h"
#include "Texture2DComponent.h"
#include "SceneManager.h"

//Static variables Init
const int m_MaxCubes = 28;

PyramidComponent::PyramidComponent(dae::Scene& scene, const glm::vec3& topCubePos)
	:m_FirstRowCubeCount(7)
	, m_CubeColumnCount(7)
	, m_CubeSrcRect{ 0,160,32,32 }
	, m_CubeDistance{ 16,24,0 }
	, m_HighestCubePos{ topCubePos }
	, m_CubeScale{ 1.0f }
{
	m_CubeDistance.x *= dae::SceneManager::GetInstance().GetCurrentScene()->GetSceneScale();
	m_CubeDistance.y *= dae::SceneManager::GetInstance().GetCurrentScene()->GetSceneScale();
	m_CubeDistance.z = 0;
	Initialize(scene);
}

void PyramidComponent::Initialize(dae::Scene& scene)
{
	CreateMap(scene);
}

void PyramidComponent::CreateMap(dae::Scene& scene)
{
	int rowCubeCount = m_FirstRowCubeCount;
	glm::vec3 highestCubePos = m_HighestCubePos;

	for (size_t j = 0; j < m_CubeColumnCount; j++)
	{
		for (size_t i = 0; i < rowCubeCount; i++)
		{
			glm::vec3 pos = highestCubePos;
			pos.x += m_CubeDistance.x * i;
			pos.y += m_CubeDistance.y * i;
			pos.z = 0;

			CreateCube(i, pos, scene);
		}
		highestCubePos.x -= m_CubeDistance.x;
		highestCubePos.y += m_CubeDistance.y;

		rowCubeCount--;
	}
}

void PyramidComponent::CreateCube(const size_t& index, const glm::vec3& pos, dae::Scene& scene)
{
	auto cube = std::make_shared<GameObject>("Cube" + std::to_string(index));
	cube->AddComponent(new TransformComponent(pos));
	cube->AddComponent(new Texture2DComponent("CubeLevel1NotActive1.png", m_CubeScale));
	m_Cubes[index] = cube;
	scene.Add(cube);
}

glm::vec3 PyramidComponent::GetCubeOffset() const
{
	return m_CubeDistance;
}