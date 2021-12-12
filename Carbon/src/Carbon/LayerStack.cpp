#include "cnpch.h"
#include "LayerStack.h"


namespace Carbon {




	LayerStack::LayerStack()
	{
		m_InsertIndex = 0;
	}

	LayerStack::~LayerStack()
	{
		for (auto it = m_Layers.begin(); it != m_Layers.end(); ++it)
		{
			(*it)->OnDetach();
			delete (*it);
		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		m_Layers.emplace(m_Layers.begin() + m_InsertIndex, layer);
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		m_Layers.emplace_back(overlay);
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			layer->OnDetach();
			m_Layers.erase(it);
			m_InsertIndex--;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end())
		{
			overlay->OnDetach();
			m_Layers.erase(it);
		}
	}

}