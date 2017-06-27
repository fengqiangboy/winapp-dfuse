
// worldView.cpp : CworldView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "world.h"
#endif

#include "worldDoc.h"
#include "worldView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CworldView

IMPLEMENT_DYNCREATE(CworldView, CView)

BEGIN_MESSAGE_MAP(CworldView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CworldView 构造/析构

CworldView::CworldView()
{
	// TODO: 在此处添加构造代码

}

CworldView::~CworldView()
{
}

BOOL CworldView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CworldView 绘制

void CworldView::OnDraw(CDC* /*pDC*/)
{
	CworldDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CworldView 打印

BOOL CworldView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CworldView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CworldView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CworldView 诊断

#ifdef _DEBUG
void CworldView::AssertValid() const
{
	CView::AssertValid();
}

void CworldView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CworldDoc* CworldView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CworldDoc)));
	return (CworldDoc*)m_pDocument;
}
#endif //_DEBUG


// CworldView 消息处理程序
