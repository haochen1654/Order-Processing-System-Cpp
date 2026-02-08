# syntax=docker/dockerfile:1
FROM gcc:15.2@sha256:bf951c48aaa5f4b884d86377071429d0e2e75d1691d33ac884a039c1b15cfb95
RUN apt-get update && apt-get install -y cmake
WORKDIR /app

COPY CMakeLists.txt .

RUN cmake -S . -B build
RUN cmake -S . -B build # If omitted, libcurl is built again when src/ is copied
RUN cmake --build build --parallel 8
COPY src/ src/
RUN cmake -S . -B build
RUN cmake --build build --parallel 8

ENTRYPOINT ["/app/build/src/challenge"]
