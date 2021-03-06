#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void DieWithSystemMessage(const char *msg) 
{
	perror(msg);
	exit(1);
}

int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
	int	 n;
	n = accept(fd, sa, salenptr);

	if ( n < 0)
		DieWithSystemMessage("accept error");
	return n;
}

void Bind(int fd, const struct sockaddr *sa, socklen_t salen)
{
	if (bind(fd, sa, salen) < 0)
		DieWithSystemMessage("bind error");
}

void Connect(int fd, const struct sockaddr *sa, socklen_t salen)
{
	if (connect(fd, sa, salen) < 0)
		DieWithSystemMessage("connect error");
}

void Getpeername(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
	if (getpeername(fd, sa, salenptr) < 0)
		DieWithSystemMessage("getpeername error");
}

void Getsockname(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
	if (getsockname(fd, sa, salenptr) < 0)
		DieWithSystemMessage("getsockname error");
}

void Getsockopt(int fd, int level, int optname, void *optval, socklen_t *optlenptr)
{
	if (getsockopt(fd, level, optname, optval, optlenptr) < 0)
		DieWithSystemMessage("getsockopt error");
}



/* include Listen */
void Listen(int fd, int backlog)
{
	if (listen(fd, backlog) < 0)
		DieWithSystemMessage("listen error");
}
/* end Listen */


ssize_t Recv(int fd, void *ptr, size_t nbytes, int flags)
{
	ssize_t	n;

	if ( (n = recv(fd, ptr, nbytes, flags)) < 0)
		DieWithSystemMessage("recv error");
	return(n);
}

ssize_t Recvfrom(int fd, void *ptr, size_t nbytes, int flags,
		 struct sockaddr *sa, socklen_t *salenptr)
{
	ssize_t	n;

	if ( (n = recvfrom(fd, ptr, nbytes, flags, sa, salenptr)) < 0)
		DieWithSystemMessage("recvfrom error");
	return(n);
}

ssize_t Recvmsg(int fd, struct msghdr *msg, int flags)
{
	ssize_t	n;
	if ( (n = recvmsg(fd, msg, flags)) < 0)
		DieWithSystemMessage("recvmsg error");
	return(n);
}

int Select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds,  struct timeval *timeout)
{
	int n;

	if ( (n = select(nfds, readfds, writefds, exceptfds, timeout)) < 0)
		DieWithSystemMessage("select error");
	return(n);		/* can return 0 on timeout */
}

void Send(int fd, const void *ptr, size_t nbytes, int flags)
{
	if (send(fd, ptr, nbytes, flags) != (ssize_t)nbytes)
		DieWithSystemMessage("send error");
}

void Sendto(int fd, const void *ptr, size_t nbytes, int flags, const struct sockaddr *sa, socklen_t salen)
{
	if (sendto(fd, ptr, nbytes, flags, sa, salen) != (ssize_t)nbytes)
		DieWithSystemMessage("sendto error");
}

void Sendmsg(int fd, const struct msghdr *msg, int flags)
{
	unsigned int	i;
	ssize_t	nbytes;

	nbytes = 0;	/* must first figure out what return value should be */
	for (i = 0; i < msg->msg_iovlen; i++)
		nbytes += msg->msg_iov[i].iov_len;

	if (sendmsg(fd, msg, flags) != nbytes)
		DieWithSystemMessage("sendmsg error");
}

void Setsockopt(int fd, int level, int optname, const void *optval, socklen_t optlen)
{
	if (setsockopt(fd, level, optname, optval, optlen) < 0)
		DieWithSystemMessage("setsockopt error");
}

void Shutdown(int fd, int how)
{
	if (shutdown(fd, how) < 0)
		DieWithSystemMessage("shutdown error");
}

int Sockatmark(int fd)
{
	int n;

	if ( (n = sockatmark(fd)) < 0)
		DieWithSystemMessage("sockatmark error");
	return(n);
}

/* include Socket */
int Socket(int family, int type, int protocol)
{
	int n;

	if ( (n = socket(family, type, protocol)) < 0)
		DieWithSystemMessage("socket error");
	return(n);
}
/* end Socket */

void Socketpair(int family, int type, int protocol, int *fd)
{
	int n;

	if ( (n = socketpair(family, type, protocol, fd)) < 0)
		DieWithSystemMessage("socketpair error");
}
