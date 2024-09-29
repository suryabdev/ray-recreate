#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>

#include "orchestra.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

class OrchestraServiceImpl final : public Orchestra:: Service {
    Status RemoteCall(ServerContext* context, const RemoteCallRequest* request,
                    RemoteCallReply* reply) override {
      std::cout << "called" << std::endl;
      return Status::OK;
    }
};

void RunServer() {
    std::string server_address("0.0.0.0:50052");
    OrchestraServiceImpl service;

    ServerBuilder builder;

    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());

    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    server->Wait();
}

int main(int argc, char** argv) {
    RunServer();

    return 0;
}