package ossbuild.gstugly;

import java.io.File;
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import ossbuild.NativeResource;
import ossbuild.OSFamily;
import ossbuild.Path;
import ossbuild.Sys;
import static org.junit.Assert.*;

/**
 *
 * @author David Hoyt <dhoyt@hoytsoft.org>
 */
public class PackageTest {
	//<editor-fold defaultstate="collapsed" desc="Setup">
	public PackageTest() {
	}

	@BeforeClass
	public static void setUpClass() throws Exception {
	}

	@AfterClass
	public static void tearDownClass() throws Exception {
	}

	@Before
	public void setUp() {
		assertTrue("These unit tests require Windows to complete", Sys.isOSFamily(OSFamily.Windows));
	}

	@After
	public void tearDown() {
	}
	//</editor-fold>

	@Test
	public void testRegistry() {
		assertTrue(Sys.initializeRegistry());

		final File binDir = Path.combine(Path.nativeResourcesDirectory, "bin/");
		final File etcDir = Path.combine(Path.nativeResourcesDirectory, "etc/");
		final File libDir = Path.combine(Path.nativeResourcesDirectory, "lib/");

		assertTrue(Path.delete(binDir));
		assertTrue(Path.delete(etcDir));
		assertTrue(Path.delete(libDir));
		assertTrue(Sys.loadNativeResources(NativeResource.GStreamer));

		//Shouldn't matter how many times we call this - it shouldn't do
		//anything different after its first initialization...
		for(int i = 0; i < 100; ++i)
			assertTrue(Sys.loadNativeResources(NativeResource.GStreamer));

		assertTrue(Path.exists(binDir));

		switch(Sys.getOSFamily()) {
			case Unix:
				assertTrue(Path.exists(Path.combine(binDir, "libmpeg2.so.0")));
				break;
			case Windows:
				assertTrue(Path.exists(Path.combine(binDir, "libmpeg2-0.dll")));
				break;
			default:
				assertTrue("Unsupported test platform", false);
				break;
		}

		assertTrue(Sys.cleanRegistry());
	}
}
