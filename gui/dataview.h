#pragma once

#include "eopcheck.hpp"
#include <vector>
#include <shared_mutex>

#define DATAVIEW()  Singleton<CDataView>::getInstance()

class CDataView
{
public:
	CDataView();
	~CDataView();

public:

	void SetSelectIndex(size_t Index);
	size_t GetSelectIndex();
	CRefPtr<CEventView> GetSelectView();
	CRefPtr<CEventView> GetView(size_t Index);
	size_t GetShowViewCounts();
	void ClearShowViews();
	void Push(CRefPtr<CEventView> pOpt);
	void ApplyNewFilter();

private:

	size_t m_SelectIndex = 0;

	//
	// ���ﱣ�������е���Ϣ
	//

	std::vector<CRefPtr<CEventView>> m_OptViews;

	//
	// ����ֻ������Ҫ��ʾ����Ϣ
	//

	std::vector<CRefPtr<CEventView>> m_ShowViews;
	std::shared_mutex m_Viewlock;
	std::shared_mutex m_OptViewlock;

	CEopCheck m_EopCheck;
};