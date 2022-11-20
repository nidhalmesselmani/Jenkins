FROM nidhamesselmani/my_docker_repo:cpp_jenkins_agent


COPY . /usr/cpp_app/
WORKDIR /usr/cpp_app/
RUN mkdir build
RUN cd build

RUN cmake ..