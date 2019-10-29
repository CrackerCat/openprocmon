#pragma once

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
	CRefPtr<COptView> GetSelectView();
	CRefPtr<COptView> GetView(size_t Index);
	size_t GetShowViewCounts();
	void ClearShowViews();
	void Push(CRefPtr<COptView> pOpt);

private:

	size_t m_SelectIndex = 0;

	//
	// ���ﱣ�������е���Ϣ
	//

	std::vector<CRefPtr<COptView>> m_OptViews;

	//
	// ����ֻ������Ҫ��ʾ����Ϣ
	//

	std::vector<CRefPtr<COptView>> m_ShowViews;
	std::shared_mutex m_Viewlock;
};