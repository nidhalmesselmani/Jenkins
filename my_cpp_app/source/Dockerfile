FROM nidhamesselmani47/jenkins_agents:cpp_jenkins_agent


COPY . /usr/cpp_app/
WORKDIR /usr/cpp_app/build

RUN cmake .. -G"Unix Makefiles"  -D CMAKE_CXX_COMPILER=g++
RUN cmake --build .
RUN ctest

CMD ["./HelloAppBinary"]
