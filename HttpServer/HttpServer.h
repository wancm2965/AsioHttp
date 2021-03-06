#pragma  once
#include "include/HttpServer/IHttpServer.h"
#include "server.hpp"
#include <set>
#include "Thread.h"
	class chttpserver : public IHttpServer
		, public KThread
	{
	public:
		chttpserver(IHttpServerNotify*pNotify);
		~chttpserver();
		void HandleHttpReq(void*handler,const char*api, const char* param,char**pReply);
	public:
		virtual int32_t StartHttpServer(const char* ip, int32_t port);
		virtual void StopHttpServer();
		virtual void RegAPIpath(const char* path);
		virtual void AsyncReply(void* handler, const char* reply);

		virtual void ThreadProcMain(void);
	private:
		IHttpServerNotify * m_pNotify;
		http::server2::server*  m_pserver;
		std::set<std::string> m_setPath;
		std::string           m_strapi;
		int32_t               m_nport;
	};



