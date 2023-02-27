FROM		debian:buster-slim

RUN			apt update && apt install -y wget												\
			&& wget https://github.com/google/cadvisor/releases/download/v0.23.4/cadvisor	\
			&& chmod +x cadvisor

EXPOSE		8080

ENTRYPOINT	["/cadvisor", "--profiling=false"]