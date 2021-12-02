# TODO: What is the correct value for the cpp_std version? It seems to be 17 (lowest version that works, c++20 is pretty recent). I think a change from wpi::math to wpi::numbers in 2022 might be to update with c++20's mirrored change, so we may need to update c++ to 20 at that time.
project('tutorial', 'cpp', default_options: ['cpp_std=c++17'])

sources = ['Robot.cpp', 'RobotContainer.cpp', 'commands/ExampleCommand.cpp', 'subsystems/ExampleSubsystem.cpp', 'subsystems/DrivetrainSubsystem.cpp']

real_sources = []
foreach source: sources
    real_sources += 'src/' + source
endforeach

cc = meson.get_compiler('cpp')

libpath = meson.current_source_dir() + '/lib/bin/linux/athena'

deps_w_headers = []
deps_wo_headers = []

libs = [
    ['hal', 'wpiHal'],
    ['wpiutil', 'wpiutil'],
    ['wpilibc', 'wpilibc'],
    ['wpimath', 'wpimath'],
    ['new_commands', 'wpilibNewCommands'],
    ['ntcore', 'ntcore']]
libs_ni_lib = [['chipobject', 'RoboRIO_FRC_ChipObject'], ['netcomm', 'FRC_NetworkCommunication'], ['visa', 'visa']]

foreach lib: libs_ni_lib
    libs += [['ni-lib/' + lib[0], lib[1]]]
endforeach

foreach lib: libs
    lib_path = 'deps/' + lib[0]
    deps_w_headers += declare_dependency(link_args: meson.current_source_dir() + '/' + lib_path + '/linux/athena/shared/' + 'lib' + lib[1] + '.so', include_directories: include_directories(lib_path + '/include'))
endforeach

libs_ni_rt = ['ni_emb', 'nirio_emb_can', 'niriosession', 'NiFpgaLv', 'ni_rtlog', 'NiFpga', 'NiRioSrv', 'niriodevenum']

foreach lib: libs_ni_rt
    lib_path = 'deps/ni-lib/rt/linux/athena/shared/lib' + lib + '.so'
    deps_w_headers += declare_dependency(link_args: meson.current_source_dir() + '/' + lib_path)
endforeach

executable('demo', real_sources, dependencies: deps_w_headers + deps_wo_headers, include_directories: include_directories('include'),
    link_args: ['-lpthread'])

compile_commands_target = custom_target('comp_cmds',
                                        output: 'compile_commands.json',
                                        command: [meson.current_source_dir() + '/compile_commands.sh', meson.current_build_dir()])
