FROM		debian:buster-slim

RUN			apt update && apt install -y wget												\
			&& wget https://github.com/google/cadvisor/releases/download/v0.47.0/cadvisor-v0.47.0-linux-amd64	\
			&& chmod +x cadvisor-v0.47.0-linux-amd64

EXPOSE		8080

ENTRYPOINT	["/cadvisor-v0.47.0-linux-amd64", "--profiling=false"]
