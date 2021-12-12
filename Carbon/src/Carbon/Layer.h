#pragma once
#include "cnpch.h"
#include "Carbon/Events/Event.h"

namespace Carbon {

	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& e) {}

#ifdef CN_DEBUG
		inline const std::string& GetDebugName() const { return m_DebugName; }
#endif

	private:
#ifdef CN_DEBUG
		std::string m_DebugName;
#endif
	};

}

