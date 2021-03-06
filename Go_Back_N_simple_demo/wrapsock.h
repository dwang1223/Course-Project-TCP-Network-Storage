void DieWithSystemMessage(const char *) ;
int Accept(int , struct sockaddr *, socklen_t *);
void Bind(int , const struct sockaddr *, socklen_t );
void Connect(int , const struct sockaddr *, socklen_t );
void Getpeername(int , struct sockaddr *, socklen_t *);
void Getsockname(int , struct sockaddr *, socklen_t *);
void Getsockopt(int , int , int , void *, socklen_t *);
void Listen(int , int );
ssize_t Recv(int , void *, size_t , int );
ssize_t Recvfrom(int , void *, size_t , int , struct sockaddr *, socklen_t *);
ssize_t Recvmsg(int , struct msghdr *, int );
int Select(int nfds, fd_set *, fd_set *, fd_set *,  struct timeval *);
void Send(int , const void *, size_t , int );
void Sendto(int , const void *, size_t , int ,  const struct sockaddr *, socklen_t );
void Sendmsg(int , const struct msghdr *, int );
void Setsockopt(int , int , int , const void *, socklen_t );
void Shutdown(int , int );
int Sockatmark(int );
int Socket(int , int , int );
void Socketpair(int , int , int , int *);
