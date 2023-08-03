# ch1
add_executable(hserver ch1/hello_server.c)
add_executable(hclient ch1/hello_client.c)

# ch2
add_executable(tserver ch2/tcp_server.c)
add_executable(tclient ch2/tcp_client.c)

# ch4
add_executable(eserver ch4/echo_server.c)
add_executable(eclient ch4/echo_client.c)

# ch5
add_executable(ueserver ch5/uecho_server.c)
add_executable(ueclient ch5/uecho_client.c)
add_executable(uecclient ch5/uecho_con_client.c)

# ch6
add_executable(fserver ch6/file_server.c)
add_executable(fclient ch6/file_client.c)

# ch7
add_executable(mserver ch7/echo_mpserv.c)
add_executable(sserver ch7/echo_selectserv.c)

# ch8
add_executable(nserver ch8/news_sender.c)
add_executable(nclient ch8/news_receiver.c)
add_executable(nserver2 ch8/news_sender2.c)
add_executable(nclient2 ch8/news_receiver2.c)