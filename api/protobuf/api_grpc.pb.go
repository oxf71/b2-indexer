// Code generated by protoc-gen-go-grpc. DO NOT EDIT.
// versions:
// - protoc-gen-go-grpc v1.3.0
// - protoc             v4.25.3
// source: api/protobuf/api.proto

package protobuf

import (
	context "context"
	vo "github.com/b2network/b2-indexer/api/protobuf/vo"
	grpc "google.golang.org/grpc"
	codes "google.golang.org/grpc/codes"
	status "google.golang.org/grpc/status"
)

// This is a compile-time assertion to ensure that this generated file
// is compatible with the grpc package it is being compiled against.
// Requires gRPC-Go v1.32.0 or later.
const _ = grpc.SupportPackageIsVersion7

const (
	HelloService_GetHello_FullMethodName = "/api.protobuf.HelloService/GetHello"
)

// HelloServiceClient is the client API for HelloService service.
//
// For semantics around ctx use and closing/ending streaming RPCs, please refer to https://pkg.go.dev/google.golang.org/grpc/?tab=doc#ClientConn.NewStream.
type HelloServiceClient interface {
	GetHello(ctx context.Context, in *vo.HelloRequest, opts ...grpc.CallOption) (*vo.HelloResponse, error)
}

type helloServiceClient struct {
	cc grpc.ClientConnInterface
}

func NewHelloServiceClient(cc grpc.ClientConnInterface) HelloServiceClient {
	return &helloServiceClient{cc}
}

func (c *helloServiceClient) GetHello(ctx context.Context, in *vo.HelloRequest, opts ...grpc.CallOption) (*vo.HelloResponse, error) {
	out := new(vo.HelloResponse)
	err := c.cc.Invoke(ctx, HelloService_GetHello_FullMethodName, in, out, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

// HelloServiceServer is the server API for HelloService service.
// All implementations must embed UnimplementedHelloServiceServer
// for forward compatibility
type HelloServiceServer interface {
	GetHello(context.Context, *vo.HelloRequest) (*vo.HelloResponse, error)
	mustEmbedUnimplementedHelloServiceServer()
}

// UnimplementedHelloServiceServer must be embedded to have forward compatible implementations.
type UnimplementedHelloServiceServer struct {
}

func (UnimplementedHelloServiceServer) GetHello(context.Context, *vo.HelloRequest) (*vo.HelloResponse, error) {
	return nil, status.Errorf(codes.Unimplemented, "method GetHello not implemented")
}
func (UnimplementedHelloServiceServer) mustEmbedUnimplementedHelloServiceServer() {}

// UnsafeHelloServiceServer may be embedded to opt out of forward compatibility for this service.
// Use of this interface is not recommended, as added methods to HelloServiceServer will
// result in compilation errors.
type UnsafeHelloServiceServer interface {
	mustEmbedUnimplementedHelloServiceServer()
}

func RegisterHelloServiceServer(s grpc.ServiceRegistrar, srv HelloServiceServer) {
	s.RegisterService(&HelloService_ServiceDesc, srv)
}

func _HelloService_GetHello_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(vo.HelloRequest)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(HelloServiceServer).GetHello(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: HelloService_GetHello_FullMethodName,
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(HelloServiceServer).GetHello(ctx, req.(*vo.HelloRequest))
	}
	return interceptor(ctx, in, info, handler)
}

// HelloService_ServiceDesc is the grpc.ServiceDesc for HelloService service.
// It's only intended for direct use with grpc.RegisterService,
// and not to be introspected or modified (even as a copy)
var HelloService_ServiceDesc = grpc.ServiceDesc{
	ServiceName: "api.protobuf.HelloService",
	HandlerType: (*HelloServiceServer)(nil),
	Methods: []grpc.MethodDesc{
		{
			MethodName: "GetHello",
			Handler:    _HelloService_GetHello_Handler,
		},
	},
	Streams:  []grpc.StreamDesc{},
	Metadata: "api/protobuf/api.proto",
}

const (
	NotifyService_TransactionNotify_FullMethodName = "/api.protobuf.NotifyService/TransactionNotify"
)

// NotifyServiceClient is the client API for NotifyService service.
//
// For semantics around ctx use and closing/ending streaming RPCs, please refer to https://pkg.go.dev/google.golang.org/grpc/?tab=doc#ClientConn.NewStream.
type NotifyServiceClient interface {
	TransactionNotify(ctx context.Context, in *vo.TransactionNotifyRequest, opts ...grpc.CallOption) (*vo.TransactionNotifyResponse, error)
}

type notifyServiceClient struct {
	cc grpc.ClientConnInterface
}

func NewNotifyServiceClient(cc grpc.ClientConnInterface) NotifyServiceClient {
	return &notifyServiceClient{cc}
}

func (c *notifyServiceClient) TransactionNotify(ctx context.Context, in *vo.TransactionNotifyRequest, opts ...grpc.CallOption) (*vo.TransactionNotifyResponse, error) {
	out := new(vo.TransactionNotifyResponse)
	err := c.cc.Invoke(ctx, NotifyService_TransactionNotify_FullMethodName, in, out, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

// NotifyServiceServer is the server API for NotifyService service.
// All implementations must embed UnimplementedNotifyServiceServer
// for forward compatibility
type NotifyServiceServer interface {
	TransactionNotify(context.Context, *vo.TransactionNotifyRequest) (*vo.TransactionNotifyResponse, error)
	mustEmbedUnimplementedNotifyServiceServer()
}

// UnimplementedNotifyServiceServer must be embedded to have forward compatible implementations.
type UnimplementedNotifyServiceServer struct {
}

func (UnimplementedNotifyServiceServer) TransactionNotify(context.Context, *vo.TransactionNotifyRequest) (*vo.TransactionNotifyResponse, error) {
	return nil, status.Errorf(codes.Unimplemented, "method TransactionNotify not implemented")
}
func (UnimplementedNotifyServiceServer) mustEmbedUnimplementedNotifyServiceServer() {}

// UnsafeNotifyServiceServer may be embedded to opt out of forward compatibility for this service.
// Use of this interface is not recommended, as added methods to NotifyServiceServer will
// result in compilation errors.
type UnsafeNotifyServiceServer interface {
	mustEmbedUnimplementedNotifyServiceServer()
}

func RegisterNotifyServiceServer(s grpc.ServiceRegistrar, srv NotifyServiceServer) {
	s.RegisterService(&NotifyService_ServiceDesc, srv)
}

func _NotifyService_TransactionNotify_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(vo.TransactionNotifyRequest)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(NotifyServiceServer).TransactionNotify(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: NotifyService_TransactionNotify_FullMethodName,
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(NotifyServiceServer).TransactionNotify(ctx, req.(*vo.TransactionNotifyRequest))
	}
	return interceptor(ctx, in, info, handler)
}

// NotifyService_ServiceDesc is the grpc.ServiceDesc for NotifyService service.
// It's only intended for direct use with grpc.RegisterService,
// and not to be introspected or modified (even as a copy)
var NotifyService_ServiceDesc = grpc.ServiceDesc{
	ServiceName: "api.protobuf.NotifyService",
	HandlerType: (*NotifyServiceServer)(nil),
	Methods: []grpc.MethodDesc{
		{
			MethodName: "TransactionNotify",
			Handler:    _NotifyService_TransactionNotify_Handler,
		},
	},
	Streams:  []grpc.StreamDesc{},
	Metadata: "api/protobuf/api.proto",
}
