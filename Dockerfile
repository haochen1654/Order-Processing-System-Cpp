# syntax=docker/dockerfile:1
FROM gcr.io/bazel-public/bazel:8.4.2

WORKDIR /app

COPY MODULE.bazel MODULE.bazel.lock ./
COPY src/ src/

RUN bazel build //src:main --compilation_mode=opt \
    && cp -L bazel-bin/src/main /usr/local/bin/main

ENTRYPOINT ["/usr/local/bin/main"]
